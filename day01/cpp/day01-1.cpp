// Part 1
#include <cstdio>
// for removing white spaces
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

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
    int compass = 0;
    string instruction;
    int block;
    int blocksEachDirection[] = {0, 0, 0, 0};
    int totalBlocks = 0;

    // get each individual instruction one bye one removing the comma
    while (getline(data, instruction, ',')) {
        if (instruction[0] == 'R') {
            compass--;
        } else {
            compass++;
        }
        // keeps the range of compass form -3,-2,-1,0,1,2,3
        // to use them as index for the array blocksEachDirection[]
        compass %= 4;

        // transforms the negative values to positive so it is can be used as a
        // valid index for the array blocksEachDirection[]
        if (compass < 0) {
            compass += 4;
        }
        // erase the first member of the string
        instruction.erase(instruction.begin() + 0);
        // convert the rest of the string to int
        block = stoi(instruction);

        blocksEachDirection[compass] += block;
    }
    totalBlocks = abs(blocksEachDirection[0] - blocksEachDirection[2]) +
                  abs(blocksEachDirection[1] - blocksEachDirection[3]);

    printf("%d\n", totalBlocks);
}
