/// Citations:
///     Code for Program::createIntegerFile inspired by https://stackoverflow.com/a/10330562/10252771

#ifndef PROGRAM_H
#define PROGRAM_H
#define NUM_INTEGERS 500000

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdint>
#include <ctime>
#include <random>
#include "HashTable.h"
using namespace std;

class Program {
private:
    HashTable * hashTableTrivial;
    HashTable * hashTableFNV;
    string iFileName;
    vector<uint64_t> data;
public:
    Program();
    ~Program();
    void run();
    static void createIntegerFile();
    void readControlFile();
    void readIntFile();
    void testAlgorithms();
};

#endif //PROGRAM_H
