#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Get the data from input.dat
vector<vector<string>> getData() {
    ifstream myReadFile;
    myReadFile.open("../input.txt");
    vector<vector<string>> data;
    while (!myReadFile.eof()) {
        for (int i = 0; i < 1; i++) {
            vector<string> tmpVec;

            // passing the data in chunks of an array of size 3
            // the tempString and tmpVec are for NOT passing the same
            // pointer everytime but a different pointer everytime
            for (int j = 0; j < 3; j++) {
                string tmpString;
                myReadFile >> tmpString;
                tmpVec.push_back(tmpString);
            }
            data.push_back(tmpVec);
        }
    }
    return data;
}

int getPossibles(vector<vector<string>> data) {
    int possibles = 0;
    // the element of data is trash so it must be discarted
    // -1 does that
    for (size_t i = 0; i < (data.size() - 1); ++i) {
        int a = stoi(data[i][0]);
        int b = stoi(data[i][1]);
        int c = stoi(data[i][2]);
        if (a + b > c && a + c > b && b + c > a) {
            possibles++;
        }
    }

    // for (auto& dimension : data) {
    //     cout << dimension[0] << endl;
    // int a = stoi(dimension[0]);
    // int b = stoi(dimension[1]);
    // int c = stoi(dimension[2]);

    // if (a + b > c && a + c > b && b + c > a) {
    //     possibles++;
    // }
    // }
    return possibles;
}

int main() {
    vector<vector<string>> data = getData();
    int possibles = getPossibles(data);
    printf("%d\n", possibles);
    return 0;
}
