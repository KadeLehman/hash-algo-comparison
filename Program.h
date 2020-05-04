/// Citations:
///     Code for Program::createIntegerFile inspired by Ivaylo Strandjev at https://stackoverflow.com/a/10330562/10252771

#ifndef PROGRAM_H
#define PROGRAM_H
#define NUM_INTEGERS 500000

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdint>
#include <ctime>
#include <chrono>
#include <random>
#include "HashTable.h"
using namespace std;
using std::chrono::steady_clock;
using time_point = std::chrono::steady_clock::time_point;
using std::chrono::duration_cast;
using std::chrono::microseconds;

class Program {
private:
    HashTable * hashTableTrivial;
    HashTable * hashTableFNV;
    string iFileName;
    vector<uint32_t> data;
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
