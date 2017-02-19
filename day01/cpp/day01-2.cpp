// Part 2
#include <cstdio>
// for removing white spaces
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

using namespace std;

void removeSpaces(string &input) {
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
}

// Get the data from input.dat
string getData() {
    string data;
    ifstream theData("../input.dat");

    if (theData.is_open()) {
        getline(theData, data);
    }

    removeSpaces(data);

    return data;
}

int main() {
    stringstream data(getData());
    string instruction;
    int pinstruction;
    int block;
    int sum = 0;
    // ifstream theData("../input.dat");
    // cout << theData.rdbuf() << endl;
    // printf("%g", theData.rdbuf());

    for (int i = 0; (getline(data, instruction, ',')); i++) {
        if (instruction[i] == pinstruction) {
            pinstruction = instruction[i];
            // erase the first member of the string
            instruction.erase(instruction.begin() + 0);
            // convert the rest of the string to int
            block = stoi(instruction);
            sum += block;
        } else {
            pinstruction = instruction[i];
        }
    }
    printf("%d", sum);
}
