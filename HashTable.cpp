#include "HashTable.h"

HashTable::HashTable() {
    lists = nullptr;
    numTotalLists = 0;
}

uint64_t HashTable::getNumCollisions() const {
    uint64_t numCollisions = 0;
    uint32_t listSize = 0;
    for (uint32_t i = 0; i < numTotalLists; i++) {
        auto first = lists[i].begin();
        auto last = lists[i].end();
        listSize = distance(first,last);
        if (listSize > 1)
            numCollisions += listSize - 1;
    }
    return numCollisions;
}

void TrivialHashTable::insert(uint32_t val) {
    lists[hash(val)].push_front(val);
}

void FNVHashTable::insert(uint32_t val) {
    lists[hash(val)].push_front(val);
}

//Trivial Hash Algorithm: mask bottom log2(tableSize) bits out of val
uint32_t TrivialHashTable::hash(uint32_t val) {
    uint32_t mask = 1;
    for (short i = 0; i < numBitsToMask - 1; i++) {
        mask <<= 1;
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
    return ++num;
}

//FNV-1a Hash Algorithm
uint32_t FNVHashTable::hash(uint32_t val) {
    uint32_t valSegment = val;
    uint32_t mask = 0xFF; //mask one byte at a time
    uint32_t hash = FNV_offset_basis;

    for (int i = 0; i < NUM_BYTES_PER_INT; i++) {
        valSegment &= mask;
        hash ^= valSegment;
        hash *= FNV_prime;
        valSegment = val >>= 8; //shift away used byte to prepare next byte for masking
    }

    //The program xor-folds the hash here in order to produce a 20-bit hash value.
    hash = (hash >> 20) ^ (hash & MAX_UINT_20);
    return hash - 1;
}
