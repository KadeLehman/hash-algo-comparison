#include "Program.h"

Program::Program() {
    iFileName = "empty_I_FILE_NAME";
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
    cout << "In testAlgorithms() function..." << endl;
    //TODO: Insert integers from vector into first hash table, then the second one.
    //TODO: Implement std::chrono, which will print algorithm runtimes to the terminal.
}
