import 'dart:io';

void main() {
  List<String> board = ["     ", " 123 ", " 456 ", " 789 ", "     "];
  int rowCoordinate = 1;
  int columnCoordinate = 1;
  // open the file and put each line of the file in a list of strings
  List<String> lines = new File('../input.dat').readAsLinesSync();
  String code = "";

  for (var i = 0; i < lines.length; i++) {
    for (var j = 0; j < lines[i].length; j++) {
      String direction = lines[i][j];
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
    code = code + board[rowCoordinate][columnCoordinate];
  }
  print(code);
}
