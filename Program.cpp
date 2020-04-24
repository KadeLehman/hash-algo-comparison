/** Citations:
 *      Stringstream code inspired by Stack Overflow
 *      https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
 */

#include "Program.h"

Program::Program() {
    tempUnsigned = 0;
}

void Program::run() {
    readControlFile();
    testAllGraphs();
}

void Program::readControlFile() {

    ifstream iFile("ControlFile.txt");

    if (!iFile.is_open()) {
        cout << "Could not open control file." << endl;
        exit(200);
    }

    //Reads line by line, running code based on each provided command in the file
    string s;
    int i = 0;
    while (iFile >> s) {
        if (s == "or") {
            iFile >> s;
            iFileName = s;
            readGraphFile(i);
            i++;
        }
        else if (s == "ow") {
            iFile >> s;
            oFileNameTemp = s;
        }
    }

    //To debug, set a breakpoint before file closing and look inside "graphs".
    iFile.close();
}


void Program::readGraphFile(int i) {

    ifstream iFile(iFileName);

    if (!iFile.is_open()) {
        cout << "Could not open graph file." << endl;
        exit(200);
    }

    //Create empty graph
    graphs.emplace_back();

    //Reads the uint, then inserts it into graph.
    string s = "empty";
    string s2 = "empty2";
    getline(iFile, s);
    s = s.substr(1, s.size() - 2);
    int numNodes = stoi(s);
    for (int j = 0; j < numNodes; j++) {
        getline(iFile, s2);
        graphs.at(i).insert(stoi(s2));
    }

    //For each trio read, pass the uints to Graph::insertRelationship function
    s = "empty";
    s2 = "empty2";
    getline(iFile, s); //Ignores line with brackets
    while (getline(iFile, s2)) { //node a, node b, weight ab
        stringstream lineStream(s2);
        string cell;
        int j = 0;
        while (getline(lineStream,cell, ',')) {
            if (j == 0)
                uintA = stoi(cell);
            else if (j == 1)
                uintB = stoi(cell);
            else if (j == 2)
                weight = stoi(cell);
            else {
                cout << iFileName << " is not formatted correctly." << endl;
                exit(200);
            }
            j++;
        }

        graphs.at(i).insertRelationship(uintA, uintB, weight);
    }

    //This is why the control file must follow up each "ow" statement with a "or" statement.
    graphs.at(i).openOutFile(oFileNameTemp);

    iFile.close();
}

void Program::testAllGraphs() {
    //TODO: Run Kruskal's algo on all graphs, collect timings <-- Ultimate goal.
    for (auto& graph : graphs) {
        graph.kruskal();
    }

    //TODO: Implement chrono, which will print the time to the terminal AND each output file.
}
