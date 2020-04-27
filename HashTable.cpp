#include "HashTable.h"

HashTable::HashTable() {
    for (auto & list : lists) {
        list = new forward_list<uint64_t>;
    }
    hashVal = 0;
}

HashTable::~HashTable() {
    for (auto & list : lists) {
        delete list;
    }
}

void HashTable::insert(uint64_t val) {
    hashVal = hash(val);
    lists[hashVal]->push_front(val);
}

uint64_t TrivialHashTable::hash(uint64_t val) {
    return 0;
}

uint64_t FNVHashTable::hash(uint64_t val) {
    return 0;
}
