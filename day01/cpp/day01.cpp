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
    string data = getData();
    stringstream linestream(data);
    int direction = 0;
    string letter;
    int steps;
    int directions[] = {0, 0, 0, 0};
    int totalSteps = 0;

    // get each individual instruction one bye one removing the comma
    while (getline(linestream, letter, ',')) {
        if (letter[0] == 'R') {
            // erase the first member of the string
            letter.erase(letter.begin() + 0);
            // convert the rest of the string to int
            steps = stoi(letter);
            direction--;
        } else {
            letter.erase(letter.begin() + 0);
            steps = stoi(letter);
            direction++;
        }
        direction %= 4;

        if (direction < 0) {
            direction += 4;
        }
        directions[direction] += steps;
    }
    totalSteps =
        abs(directions[0] - directions[2]) + abs(directions[1] - directions[3]);

    printf("%d", totalSteps);
}
