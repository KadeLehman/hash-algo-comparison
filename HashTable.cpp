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

void HashTable::setTrivialHashing() {
    isTrivialHashing = true;
}

void HashTable::trivialInsert(uint64_t val) {
    //hashVal = trivialHash(val);
    //lists[hashVal]->push_front(val);
}

void HashTable::FNVInsert(uint64_t val) {
    //hashVal = FNVHash(val);
    //lists[hashVal]->push_front(val);
}

void HashTable::trivialHash(uint64_t val) {

}

void HashTable::FNVHash(uint64_t val) {

}
