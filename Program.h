#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdint>

using namespace std;

class Program {
private:
    //Hash Table
    uint16_t tempUnsigned;

public:
    Program();
    void run();
    void readControlFile();
    void readGraphFile(int);
    void testAllGraphs();
};

#endif //PROGRAM_H
