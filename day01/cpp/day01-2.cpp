// Part 2
#include <cstdio>
// for removing white spaces
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// for some reason data has to be reference
int getDistance(stringstream &data) {
    // facing direction (N,E,S,W)
    // oscillate between 0,1,2,3
    int compass = 0;
    string instruction;
    int blocks;
    vector<int> location = {0, 0};
    vector<vector<int>> memorizeLocation;
    int factor[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int distance = 0;

    // get each individual instruction one bye one removing the comma
    while (getline(data, instruction, ',')) {
        if (instruction[0] == 'L') {
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
        blocks = stoi(instruction);

        for (int i = 0; i < blocks; i++) {
            location[0] += factor[compass][0];
            location[1] += factor[compass][1];
            vector<int> currentLocation;
            currentLocation = location;

            for (int i = 0; i < memorizeLocation.size(); i++) {
                if ((memorizeLocation[i][0] == currentLocation[0]) &&
                    (memorizeLocation[i][1] == currentLocation[1])) {
                    distance =
                        abs(currentLocation[0]) + abs(currentLocation[1]);
                    return distance;
                }
            }
            memorizeLocation.push_back(currentLocation);
        }
    }
    return distance;
}

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
    int distance = getDistance(data);
    printf("%d\n", distance);
}
