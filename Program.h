#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdint>
#include "HashTable.h"
using namespace std;

class Program {
private:
    HashTable * trivialHashTable;
    HashTable * FNVHashTable;
    string iFileName;
    vector<uint64_t> data;

public:
    Program();
    void run();
    void readControlFile();
    void readIntFile();
    void testAlgorithms();
};

#endif //PROGRAM_H
