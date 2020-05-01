/// Citations:
///     Code for TrivialHashTable::roundUpBaseTwo from https://stackoverflow.com/a/466242/10252771

#ifndef HASHTABLE_H
#define HASHTABLE_H

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
    uint64_t hashVal;
    virtual uint64_t hash(uint64_t) = 0;
public:
    HashTable();
    virtual ~HashTable() = default;
    virtual void insert(uint64_t) = 0;
};

class TrivialHashTable : public HashTable {
private:
    uint64_t hash(uint64_t) override;
    uint32_t roundUpBaseTwo(uint32_t);
    forward_list<uint64_t> * lists;
    short numBitsToMask;
public:
    explicit TrivialHashTable(uint32_t numIntegers) : HashTable() {
        //Trivial hash algorithm uses a table size that is a power of two.
        numTotalLists = roundUpBaseTwo(numIntegers) / 4;
        lists = new forward_list<uint64_t> [numTotalLists];
        numBitsToMask = log2(numTotalLists);
    }
    ~TrivialHashTable() override {
        delete [] lists;
    }
    void insert(uint64_t) override;
};

class FNVHashTable : public HashTable {
private:
    uint64_t hash(uint64_t) override;
    forward_list<uint64_t> * lists;
public:
    explicit FNVHashTable(uint32_t numIntegers) : HashTable() {
        numTotalLists = numIntegers;
        //look at FNV wiki page for how to determine size of hash table (i.e. how to modify numTotalLists)
        lists = new forward_list<uint64_t> [numTotalLists];
    }
    ~FNVHashTable() override {
        delete [] lists;
    }
    void insert(uint64_t) override;
};

#endif //HASHTABLE_H
