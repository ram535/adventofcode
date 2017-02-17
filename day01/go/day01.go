package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// this return the data of the file as a slice of intergers
	// so I have to use string() method to decode the unicode
	// dat, _ := ioutil.ReadFile("../input.dat")
	// fmt.Println(dat)

	// Open the file and scan it.
	f, _ := os.Open("../input.dat")
	scanner := bufio.NewScanner(f)

	// get the first line of the file as a string
	// if there were multiples line use a loop
	scanner.Scan()
	line := scanner.Text()

	// Split the line on commas and space.
	instructions := strings.Split(line, ", ")

	direction := 0
	directions := [...]int{0, 0, 0, 0}

	// Loop over the instructions from the string.
	for i := range instructions {
		if instructions[i][0] == 'R' {
			direction--
		} else {
			direction++
		}
		// keeps the range of direction form -3,-2,-1,0,1,2,3
		// to use them as index for the array directions[]
		direction %= 4

		// transforms the negative values to positive so it is can be used as a
		// valid index for the array directions[]
		if direction < 0 {
			direction += 4
		}

		// convert the rest of the string to int
		step, _ := strconv.Atoi(instructions[i][1:])

		directions[direction] += step
	}

	// the method math.Abs in golang only works wit float numbers
	totalSteps := math.Abs(float64(directions[0]-directions[2])) + math.Abs(float64(directions[1]-directions[3]))
	fmt.Println(totalSteps)
}
