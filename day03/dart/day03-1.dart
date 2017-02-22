import 'dart:io';

void main() {
  getData();
  List<String> triangles = getData();
  int possibleTriangle = getPossibles(triangles);
  print(possibleTriangle);
}

// get the data from the input.txt and put it in list of strings
List<String> getData() {
  // open the file and asign the content of the file to the variable
  // delete white spaces at the beginning and end of the file
  String datas = new File('../input.txt').readAsStringSync().trim();
  // split into lines
  List<String> lines = datas.split("\n");

  var triangles = new List();
  // split into individual elements into a list [][3]
  for (var line in lines) {
    // split and removes double white spaces
    List<String> temp = line.trim().split("  ");
    removeEmptyElements(temp);
    triangles.add(temp);
  }
  return triangles;
}

void removeEmptyElements(List<String> temp) {
  int i = 0;
  for (var x in temp) {
    if (x.isEmpty) {
      temp.removeAt(i);
      break;
    }
    i++;
  }
}

// calculate the number of possible triangles
int getPossibles(List<String> triangles) {
  int total = 0;
  for (var triangle in triangles) {
    // sides of the triangle
    int a = int.parse(triangle[0]);
    int b = int.parse(triangle[1]);
    int c = int.parse(triangle[2]);

    if (a + b > c && a + c > b && b + c > a) {
      total++;
    }
  }
  return total;
}
