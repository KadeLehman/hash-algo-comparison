#include "HashTable.h"

HashTable::HashTable() {
    numTotalLists = 0;
    numNonEmptyLists = 0;
    hashVal = 0;
}

void TrivialHashTable::insert(uint64_t val) {
    hashVal = hash(val);
    lists[hashVal].push_front(val);
}

void FNVHashTable::insert(uint64_t val) {
    hashVal = hash(val);
    lists[hashVal].push_front(val);
}

uint64_t TrivialHashTable::hash(uint64_t val) {
    //TODO: mask bottom log2(tableSize) bits
    return 0;
}

//Function accepts a number, then rounds it up to the nearest number that is a power of two.
uint32_t TrivialHashTable::roundUpBaseTwo(uint32_t num) {
    num--;
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 8;
    num |= num >> 16;
    return num;
}

uint64_t FNVHashTable::hash(uint64_t val) {
    return 0;
}
