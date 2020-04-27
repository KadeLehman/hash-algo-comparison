#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <cstdint>
using namespace std;

class HashTable {
protected:
    uint32_t numTotalLists;
    uint32_t numNonEmptyLists;
    uint64_t hashVal;
    virtual uint64_t hash(uint64_t) = 0;
public:
    HashTable();
    virtual void insert(uint64_t) = 0;
};

class TrivialHashTable : public HashTable {
private:
    uint64_t hash(uint64_t) override;
    forward_list<uint64_t> * lists;
public:
    explicit TrivialHashTable(uint32_t numIntegers) : HashTable() {
        numTotalLists = numIntegers;
        //round up numTotalLists to nearest power of two
        lists = new forward_list<uint64_t> [numTotalLists];
    }
    ~TrivialHashTable() {
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
    ~FNVHashTable() {
        delete [] lists;
    }
    void insert(uint64_t) override;
};

#endif //HASHTABLE_H
