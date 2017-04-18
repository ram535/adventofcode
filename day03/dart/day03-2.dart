import 'dart:io';

void main() {
  getData();
  List<String> dimensions = getData();
  int possibleTriangle = getPossibles(dimensions);
  print(possibleTriangle);
}

// get the data from the input.txt and put it in list of strings
List<String> getData() {
  // open the file and asign the content of the file to the variable
  // delete white spaces at the beginning and end of the file
  String datas = new File('../input.txt').readAsStringSync().trim();
  // split into lines
  List<String> lines = datas.split("\n");

  var dimensions = new List();
  // split into individual elements into a list [][3]
  for (var line in lines) {
    // split and removes double white spaces
    List<String> temp = line.trim().split("  ");
    removeEmptyElements(temp);
    dimensions.add(temp);
  }
  return dimensions;
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
int getPossibles(List<String> dimensions) {
  int total = 0;
  List triangles = new List.generate(3, (_) => new List(3));
  int j = 0;
  for (var dimension in dimensions) {
    triangles[0][j] = dimension[0];
    triangles[1][j] = dimension[1];
    triangles[2][j] = dimension[2];
    j++;
    if (j > 2) {
      j = 0;
      for (var triangle in triangles) {
        // sides of the triangle
        int a = int.parse(triangle[0]);
        int b = int.parse(triangle[1]);
        int c = int.parse(triangle[2]);

        if (a + b > c && a + c > b && b + c > a) {
          total++;
        }
      }
    }
  }
  return total;
}
