#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <cstdint>
using namespace std;

class HashTable {
private:
    forward_list<uint64_t> * lists[40];
    uint64_t hashVal;
    virtual uint64_t hash(uint64_t) = 0;
public:
    HashTable();
    ~HashTable();
    void insert(uint64_t);
};

class TrivialHashTable : public HashTable {
private:
    uint64_t hash(uint64_t) override;
public:
    TrivialHashTable() : HashTable() {}
};

class FNVHashTable : public HashTable {
private:
    uint64_t hash(uint64_t) override;
public:
    FNVHashTable() : HashTable() {}
};

#endif //HASHTABLE_H
