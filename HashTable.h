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
    bool isTrivialHashing;
    virtual void hash(uint64_t);
public:
    HashTable();
    virtual ~HashTable();
    void setTrivialHashing();
    void insert(uint64_t);
};

class TrivialHashTable : private HashTable {
private:
    //trivial hash function
public:
    //constructor
    //destructor
};

class FNVHashTable : private HashTable {
private:
    //FNV hash function
public:
    //constructor
    //destructor
};

#endif //HASHTABLE_H
