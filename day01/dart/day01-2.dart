import 'dart:io';

void main() {
  // open the file and asign the content of the file to the variable
  String data = new File('../input.dat').readAsStringSync();
  print(getDistance(data));
}

int getDistance(String data) {
  List<String> instructions = data.split(', ');

  // indicates where we are facing at(north, east, west ,sout)
  // its value oscillate from 0 to 3 representing each direction
  int compass = 0;

  // initial location
  List<int> location = [0, 0];
  var memorizeX = new List();
  var memorizeY = new List();

  List<int> factor = [0, 1, 0, -1];
  List<int> factor2 = [1, 0, -1, 0];

  int distance = 0;

  for (String instruction in instructions) {
    // if (instruction.substring(0, 1) == 'R') {
    if (instruction[0] == 'L') {
      compass--;
    } else {
      compass++;
    }
    // keeps the range of compass form -3,-2,-1,0,1,2,3
    compass %= 4;

    // transforms the negative values to positive so it oscillate from 0 to 3
    if (compass < 0) {
      compass += 4;
    }

    var blocks = int.parse(instruction.substring(1));
    for (var i = 0; i < blocks; i++) {
      int x = location[0] + factor[compass];
      int y = location[1] + factor2[compass];
      location[0] = x;
      location[1] = y;
      print(location);

      memorizeX.add(x);
      memorizeY.add(y);
    }
  }

  return distance;
}
