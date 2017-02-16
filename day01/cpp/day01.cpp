#include <cstdio>
// for removing white spaces
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
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
    int direction = 0;
    string letter;
    int steps;
    int directions[] = {0, 0, 0, 0};
    int totalSteps = 0;

    // get each individual instruction one bye one removing the comma
    while (getline(data, letter, ',')) {
        if (letter[0] == 'R') {
            direction--;
        } else {
            direction++;
        }
        // keeps the range of direction form -3,-2,-1,0,1,2,3
        // to use them as index for the array directions[]
        direction %= 4;

        // transforms the negative values to positive so it is can be used as a
        // valid index for the array directions[]
        if (direction < 0) {
            direction += 4;
        }
        // erase the first member of the string
        letter.erase(letter.begin() + 0);
        // convert the rest of the string to int
        steps = stoi(letter);

        directions[direction] += steps;
    }
    totalSteps =
        abs(directions[0] - directions[2]) + abs(directions[1] - directions[3]);

    printf("%d\n", totalSteps);
}
