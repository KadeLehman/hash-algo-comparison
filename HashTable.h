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
    virtual uint64_t hash(uint64_t);
public:
    HashTable();
    virtual ~HashTable();
    void insert(uint64_t);
};

class TrivialHashTable : public HashTable {
private:
    uint64_t hash(uint64_t) override;
public:
    //constructor
    //destructor
};

class FNVHashTable : public HashTable {
private:
    uint64_t hash(uint64_t) override;
public:
    //constructor
    //destructor
};

#endif //HASHTABLE_H
