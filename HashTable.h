/// Citations:
///     Code for TrivialHashTable::roundUpBaseTwo from https://stackoverflow.com/a/466242/10252771

#ifndef HASHTABLE_H
#define HASHTABLE_H
#define MAX_UINT_24 0xFFFFFF // 2^24-1
#define NUM_BYTES_PER_INT 4
#define FNV_offset_basis 0x811C9DC5
#define FNV_prime 0x01000193

#include <iostream>
#include <array>
#include <forward_list>
#include <cstdint>
#include <cmath>
using namespace std;

class HashTable {
protected:
    uint32_t numTotalLists;
    uint32_t numNonEmptyLists;
    uint32_t hashVal;
    virtual uint32_t hash(uint32_t) = 0;
public:
    HashTable();
    virtual ~HashTable() = default;
    virtual void insert(uint32_t) = 0;
};

class TrivialHashTable : public HashTable {
private:
    uint32_t hash(uint32_t) override;
    uint32_t roundUpBaseTwo(uint32_t);
    forward_list<uint32_t> * lists;
    short numBitsToMask;
public:
    explicit TrivialHashTable(uint32_t numIntegers) : HashTable() {
        //Trivial hash algorithm uses a table size that is a power of two.
        numTotalLists = roundUpBaseTwo(numIntegers) / 4;
        lists = new forward_list<uint32_t> [numTotalLists];
        numBitsToMask = log2(numTotalLists);
    }
    ~TrivialHashTable() override {
        delete [] lists;
    }
    void insert(uint32_t) override;
};

class FNVHashTable : public HashTable {
private:
    uint32_t hash(uint32_t) override;
    forward_list<uint32_t> * lists;
public:
    explicit FNVHashTable() : HashTable() {
        numTotalLists = MAX_UINT_24;
        lists = new forward_list<uint32_t> [numTotalLists];
    }
    ~FNVHashTable() override {
        delete [] lists;
    }
    void insert(uint32_t) override;
};

#endif //HASHTABLE_H
