package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// arrange the data and returns an array[][] with all the dimensions
func getData() [][3]int {
	file, _ := os.Open("../../input.txt")
	scanner := bufio.NewScanner(file)

	dimensions := [][3]int{}
	for scanner.Scan() {
		// Fields splits the string s around each instance of one or more consecutive white space characters
		// returning an array of substrings
		data := strings.Fields(scanner.Text())

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
	possibles := 0
	for _, dimension := range dimensions {
		a := dimension[0]
		b := dimension[1]
		c := dimension[2]

		if a+b > c && a+c > b && b+c > a {
			possibles++
		}
	}
	return possibles
}

func main() {
	dimensions := getData()
	possibles := getPossibles(dimensions)
	fmt.Println(possibles)

}
