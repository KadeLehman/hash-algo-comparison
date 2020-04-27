#include "HashTable.h"

HashTable::HashTable() {
    for (auto & list : lists) {
        list = new forward_list<uint64_t>;
    }
    hashVal = 0;
    isTrivialHashing = false;
}

HashTable::~HashTable() {
    for (auto & list : lists) {
        delete list;
    }
}

void HashTable::insert(uint64_t val) {
    //hashVal = hash(val);
    //lists[hashVal]->push_front(val);
}
