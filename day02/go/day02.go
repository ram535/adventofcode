package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	board := []string{"     ", " 1234 ", " 456 ", " 789 ", "     "}
	rowCoordinate := 1
	columnCoordinate := 1
	code := ""

	// Open the file.
	theData, _ := os.Open("../input.dat")
	// Create a new Scanner for the file.
	scanner := bufio.NewScanner(theData)
	// Loop over all lines in the file and print them.
	for scanner.Scan() {
		line := scanner.Text()
		for i := 0; i < len(line); i++ {
			direction := (string(line[i]))
			dr := 0
			dc := 0

			switch direction {
			case "U":
				dr = -1
			case "D":
				dr = 1
			case "L":
				dc = -1
			case "R":
				dc = 1
			}

			if string(board[rowCoordinate+dr][columnCoordinate+dc]) != " " {
				rowCoordinate = rowCoordinate + dr
				columnCoordinate = columnCoordinate + dc
			}
		}

		code = code + string(board[rowCoordinate][columnCoordinate])
	}

	fmt.Println(code)
}
