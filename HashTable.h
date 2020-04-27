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
    forward_list<uint64_t> * lists[40]{};
    uint64_t hashVal;
    bool isTrivialHashing;
public:
    HashTable();
    ~HashTable();
    void insert(uint64_t);
};

#endif //HASHTABLE_H
