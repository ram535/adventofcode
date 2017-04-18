package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	dimensions := getData()
	possibles := getPossibles(dimensions)
	fmt.Println(possibles)
}

// arrange the data and returns an array[][] with all the dimensions
func getData() [][3]int {
	file, _ := os.Open("../../input.txt")
	scanner := bufio.NewScanner(file)

	dimensions := [][3]int{}
	for scanner.Scan() {
		// Fields splits the string around each instance of one or more consecutive white space characters
		// returning an array of substrings
		data := strings.Fields(scanner.Text())

		// dimension of each side of the triangle
		// it is used only to pass all the dimensions of the triangles to the variable dimensions
		abcDimensions := [3]int{}
		// convert strings to integers
		for index, token := range data {
			abcDimensions[index], _ = strconv.Atoi(token)
		}
		dimensions = append(dimensions, abcDimensions)
	}
	return dimensions
}

func getPossibles(dimensions [][3]int) int {
	var possibles int
	var triangles [3][3]int
	var j int
	for i, dimension := range dimensions {
		triangles[0][j] = dimension[0]
		triangles[1][j] = dimension[1]
		triangles[2][j] = dimension[2]
		j++
		if j > 2 {
			j = 0
			fmt.Println(i)
			for _, triangle := range triangles {
				a := triangle[0]
				b := triangle[1]
				c := triangle[2]

				if a+b > c && a+c > b && b+c > a {
					possibles++
				}
			}
		}
	}
	return possibles
}
