#include <cstdio>
// this library allows to read and write from files
#include <fstream>
#include <string>

using namespace std;

int main() {
    string board[] = {"     ", " 123 ", " 456 ", " 789 ", "     "};
    string line;
    // this is the starting position (Button 1)
    int rowCoordinate = 1;
    int columnCoordinate = 1;

    // ifstream theData;
    // theData.open("../input.dat");
    // we associate the file inpu.dat we the object theData
    // we are also open it
    // this the same as the code above in line 12 and 13
    ifstream theData("../input.dat");

    // checking if the file input.dat was opened succefully
    if (theData.is_open()) {
        // loop that reads the file line by line, using getline
        // The value returned by getline is a reference to the stream object
        // itself, which when evaluated as a boolean expression (as in this
        // while-loop) is true if the stream is ready for more operations, and
        // false if either the end of the file has been reached or if some other
        // error occurred.
        while (getline(theData, line)) {
            char code;
            // looping each line to get the code of each line
            for (int i = 0; i < line.length(); i++) {
                char direction = line[i];
                int dr = 0;
                int dc = 0;
                switch (direction) {
                    case 'U':
                        dr = -1;
                        break;
                    case 'D':
                        dr = 1;
                        break;
                    case 'L':
                        dc = -1;
                        break;
                    case 'R':
                        dc = 1;
                        break;
                }
                if (board[rowCoordinate + dr][columnCoordinate + dc] != ' ') {
                    rowCoordinate = rowCoordinate + dr;
                    columnCoordinate = columnCoordinate + dc;
                }
            }
            code = board[rowCoordinate][columnCoordinate];
            printf("%c", code);
        }
        theData.close();
    }

    else
        printf("Unable to open file");

    return 0;
}
