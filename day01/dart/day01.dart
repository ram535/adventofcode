import 'dart:io';

void main() {
  // open the file and asign the content of the file to the variable
  String data = new File('../input.dat').readAsStringSync();
  List<String> instructions = data.split(', ');
  int compass = 0;

  // steps on each direction (north, east, west, south)
  List<int> directionSteps = [0, 0, 0, 0];
  int totalSteps = 0;

  for (String instruction in instructions) {
    // if (instruction.substring(0, 1) == 'R') {
    if (instruction[0] == 'R') {
      compass--;
    } else {
      compass++;
    }
    // keeps the range of compass form -3,-2,-1,0,1,2,3
    // to use them as index for the array directionSteps[]
    compass %= 4;

    // transforms the negative values to positive so it is can be used as a
    // valid index for the array directionSteps[]
    if (compass < 0) {
      compass += 4;
    }

    directionSteps[compass] += int.parse(instruction.substring(1));
  }

  totalSteps += (directionSteps[0] - directionSteps[2]).abs() +
      (directionSteps[1] - directionSteps[3]).abs();

  print("algo");
  print(totalSteps);
}
