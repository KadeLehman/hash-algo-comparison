#include "Program.h"

Program::Program() {
    hashTableTrivial = nullptr;
    hashTableFNV = nullptr;
    iFileName = "empty_I_FILE_NAME";
}

Program::~Program() {
    delete hashTableTrivial;
    delete hashTableFNV;
}

void Program::run() {
    readControlFile();
    testAlgorithms();
}

void Program::readControlFile() {

    ifstream iFile("ControlFile.txt");

    if (!iFile.is_open()) {
        cout << "Could not open control file." << endl;
        exit(200);
    }

    //Reads line by line, running code based on each provided command in the file
    string str;
    while (iFile >> str) {
        if (str == "or") {
            iFile >> str;
            iFileName = str;
            readIntFile();
        }
    }

    //To debug, set a breakpoint before file closing and look inside the hash tables.
    iFile.close();
}


void Program::readIntFile() {

    ifstream iFile(iFileName);

    if (!iFile.is_open()) {
        cout << "Could not open integer file." << endl;
        exit(200);
    }

    //Reads the integer, then inserts it into vector.
    string str = "empty_TEMP_STRING";
    while (getline(iFile, str)) {
        data.push_back(stoull(str));
    }

    iFile.close();
}

void Program::testAlgorithms() {
    hashTableTrivial = new TrivialHashTable(data.size());
    hashTableFNV = new FNVHashTable(data.size());

    cout << "Inserting into trivial hash table..." << endl;
    for (auto & num : data) {
        hashTableTrivial->insert(num);
    }
    cout << "Inserted all data into trivial hash table." << endl;

    //TODO: Insert integers from vector into second hash table.
    //TODO: Make a better set of integers in aTonOfIntegers.txt
    //TODO: Implement std::chrono, which will print algorithm runtimes to the terminal.
}
