#include "HashTable.h"

HashTable::HashTable(uint32_t numIntegers) {
    numTotalLists = numIntegers;
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
    //mask bottom six bits into table of size (2^6 = 64)
    return 0;
}

uint64_t FNVHashTable::hash(uint64_t val) {
    return 0;
}
