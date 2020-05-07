/// Citations:
///     Code for TrivialHashTable::roundUpBaseTwo from https://stackoverflow.com/a/466242/10252771

#ifndef HASHTABLE_H
#define HASHTABLE_H
#define MAX_UINT_20 0xFFFFF // 2^20-1
#define NUM_BYTES_PER_INT 4
#define FNV_offset_basis 0x811C9DC5
#define FNV_prime 0x01000193

#include <iostream>
#include <forward_list>
#include <iterator>
#include <cstdint>
#include <cmath>
using namespace std;

class HashTable {
protected:
    forward_list<uint32_t> * lists;
    virtual uint32_t hash(uint32_t) = 0;
    uint32_t numTotalLists;
public:
    HashTable();
    virtual ~HashTable() = default;
    uint64_t getNumCollisions() const;
    virtual void insert(uint32_t) = 0;
};

class TrivialHashTable : public HashTable {
private:
    uint32_t hash(uint32_t) override;
    uint32_t roundUpBaseTwo(uint32_t);
    short numBitsToMask;
public:
    explicit TrivialHashTable(uint32_t numIntegers) : HashTable() {
        ///Trivial hash algorithm uses a table size that is a power of two.
        numTotalLists = roundUpBaseTwo(numIntegers) / 4;
        lists = new forward_list<uint32_t> [numTotalLists];
        numBitsToMask = log2(numTotalLists);
    }
    ~TrivialHashTable() override { delete [] lists; }
    void insert(uint32_t) override;
};

class FNVHashTable : public HashTable {
private:
    uint32_t hash(uint32_t) override;
public:
    explicit FNVHashTable() : HashTable() {
        numTotalLists = MAX_UINT_20;
        lists = new forward_list<uint32_t> [numTotalLists];
    }
    ~FNVHashTable() override { delete [] lists; }
    void insert(uint32_t) override;
};

#endif //HASHTABLE_H
