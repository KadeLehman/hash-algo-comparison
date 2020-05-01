#include "HashTable.h"

HashTable::HashTable() {
    numTotalLists = 0;
    numNonEmptyLists = 0;
    hashVal = 0;
}

void TrivialHashTable::insert(uint32_t val) {
    hashVal = hash(val);
    lists[hashVal].push_front(val);
}

void FNVHashTable::insert(uint32_t val) {
    hashVal = hash(val);
    lists[hashVal].push_front(val);
}

//Trivial Hash Algorithm: mask bottom log2(tableSize) bits out of val
uint32_t TrivialHashTable::hash(uint32_t val) {
    uint32_t mask = 1;
    for (short i = 0; i < numBitsToMask - 1; i++) {
        mask = mask << 1;
        mask += 1;
    }
    val &= mask;
    return val;
}

//Function accepts a number, then rounds it up to the nearest number that is a power of two.
uint32_t TrivialHashTable::roundUpBaseTwo(uint32_t num) {
    num--;
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 8;
    num |= num >> 16;
    num++;
    return num;
}

//FNV-1a Hash Algorithm
uint32_t FNVHashTable::hash(uint32_t val) {
    uint32_t valSegment = val;
    uint32_t mask = 0xFF; //mask one byte at a time
    uint32_t hash = FNV_offset_basis;

    for (int i = 0; i < NUM_BYTES_PER_INT; i++) {
        valSegment &= mask;
        //store result
        hash ^= valSegment;
        hash *= FNV_prime;
        valSegment = val >> 4;
    }

    return val;
}
