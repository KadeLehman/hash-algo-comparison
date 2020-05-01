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
    createIntegerFile();
    readControlFile();
    testAlgorithms();
}

void Program::createIntegerFile() {
    //TODO: GENERATE NEW INTEGER LIST THAT IS UNEVENLY DISTRIBUTED (see Stack Overflow)
    ofstream file("intList.txt");
    int first_lo = 1, first_hi = 3000; // 1/2 chance to choose a number in [first_lo, first_hi]
    int second_lo = 3001, second_hi = 7000; // 1/6 chance to choose a number in [second_lo, second_hi]
    int third_lo = 7001, third_hi = 10000;// 1/3 chance to choose a number in [third_lo, third_hi]
    long temp = random() % 6;
    for (int i = 0; i < NUM_INTEGERS; i++) {
        if (temp <= 2) {
            file << random() % 3001 << endl;
        } else if (temp <= 3) {
            file << random() % 4000 + second_lo << endl;
        } else  {
            file << random() % 3000 + third_lo << endl;
        }
    }
    file.close();
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
