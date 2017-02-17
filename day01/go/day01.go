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

	compass := 0
	// steps of each direction (north, east, west, south)
	directionSteps := [...]int{0, 0, 0, 0}

	// Loop over the instructions from the string.
	for i := range instructions {
		if instructions[i][0] == 'R' {
			compass--
		} else {
			compass++
		}
		// keeps the range of compass form -3,-2,-1,0,1,2,3
		// to use them as index for the array directionSteps[]
		compass %= 4

		// transforms the negative values to positive so it is can be used as a
		// valid index for the array directionSteps[]
		if compass < 0 {
			compass += 4
		}

		// convert the rest of the string to int
		step, _ := strconv.Atoi(instructions[i][1:])

		directionSteps[compass] += step
	}

	// the method math.Abs in golang only works wit float numbers
	totalSteps := math.Abs(float64(directionSteps[0]-directionSteps[2])) + math.Abs(float64(directionSteps[1]-directionSteps[3]))
	fmt.Println(totalSteps)
}
