import 'dart:io';

void main() {
  // open the file and asign the content of the file to the variable
  String data = new File('../input.dat').readAsStringSync();
  List<String> instructions = data.split(', ');

  // blocks on each direction (north, east, west, south)
  List<int> blocksPerDirection = [0, 0, 0, 0];

  blocksPerDirection = getBlocks(instructions, blocksPerDirection);

  int totalBlocks = (blocksPerDirection[0] - blocksPerDirection[2]).abs() +
      (blocksPerDirection[1] - blocksPerDirection[3]).abs();

  print(totalBlocks);
}

List<int> getBlocks(List<String> instructions, List<int> blocksPerDirection) {
  int compass = 0;
  for (String instruction in instructions) {
    // if (instruction.substring(0, 1) == 'R') {
    if (instruction[0] == 'R') {
      compass--;
    } else {
      compass++;
    }
    // keeps the range of compass form -3,-2,-1,0,1,2,3
    // to use them as index for the array blocksPerDirection[]
    compass %= 4;

    // transforms the negative values to positive so it is can be used as a
    // valid index for the array blocksPerDirection[]
    if (compass < 0) {
      compass += 4;
    }

    blocksPerDirection[compass] += int.parse(instruction.substring(1));
  }

  return blocksPerDirection;
}
