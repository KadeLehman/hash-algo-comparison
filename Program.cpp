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
    //createIntegerFile();
    readControlFile();
    testAlgorithms();
}

void Program::createIntegerFile() {
    ///Setup
    ofstream file("intList.txt");
    int first_lo = 100000, first_hi = 199999; // 1/2 chance to choose a number in [first_lo, first_hi]
    int second_lo = 200000, second_hi = 499999; // 1/6 chance to choose a number in [second_lo, second_hi]
    int third_lo = 500000, third_hi = 599999;// 1/3 chance to choose a number in [third_lo, third_hi]
    srandom(time(nullptr));

    ///Generating and outputting integers to file
    for (int i = 0; i < NUM_INTEGERS; i++) {
        //Possible numbers that "temp" is: 0,1,2,3,4,5 (six possible outcomes)
        long temp = random() % 6;
        if (temp <= 2) // 0,1,2 = 3/6 = 1/2 probability
            file << random() % (first_hi - first_lo + 1) + first_lo << endl;
        else if (temp <= 3) // 3 = 1/6 probability
            file << random() % (second_hi - second_lo + 1) + second_lo << endl;
        else // 4,5 = 2/6 = 1/3 probability
            file << random() % (third_hi - third_lo + 1) + third_lo << endl;
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
    hashTableFNV = new FNVHashTable();
    const int oneMillion = 1000000;
    time_point start;
    time_point end;

    ///Test Trivial
    cout << "Inserting into trivial hash table..." << endl;
    start = steady_clock::now();
    for (auto & num : data) hashTableTrivial->insert(num);
    end = steady_clock::now();
    cout << "Inserted all data into trivial hash table in "
         << duration_cast<microseconds>(end - start).count() / oneMillion
         << " seconds." << endl;

    ///Test FNV
    cout << "Inserting into FNV hash table..." << endl;
    start = steady_clock::now();
    for (auto & num : data) hashTableFNV->insert(num);
    end = steady_clock::now();
    cout << "Inserted all data into FNV hash table in "
         << duration_cast<microseconds>(end - start).count() / oneMillion
         << " seconds." << endl;
}
