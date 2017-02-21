// this help me to understand slices more clearly.
// http://stackoverflow.com/questions/42352362/golang-slice-append-built-in-function-returning-value/42352909#42352909
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"reflect"
	"strconv"
	"strings"
)

func getDistance(instructions []string) float64 {
	compass := 0

	location := []int{0, 0}
	memorizeLocation := [][]int{}

	factor := [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
	var distance float64

	// Loop over the instructions from the string.
	for i := range instructions {
		if instructions[i][0] == 'L' {
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
		blocks, _ := strconv.Atoi(instructions[i][1:])

		for i := 0; i < blocks; i++ {
			currentLocation := []int{0, 0}
			location[0] += factor[compass][0]
			location[1] += factor[compass][1]
			copy(currentLocation, location)
			fmt.Println(currentLocation)

			for _, check := range memorizeLocation {
				if reflect.DeepEqual(check, currentLocation) {
					distance := math.Abs(float64(currentLocation[0])) + math.Abs(float64(currentLocation[1]))
					return distance
				}
			}

			memorizeLocation = append(memorizeLocation, currentLocation)
		}
	}
	return distance
}

func main() {
	// Open the file and scan it.
	f, _ := os.Open("../../input.dat")
	scanner := bufio.NewScanner(f)

	// get the first line of the file as a string
	// if there were multiples line use a loop
	scanner.Scan()
	line := scanner.Text()

	// Split the line on commas and space.
	instructions := strings.Split(line, ", ")

	fmt.Println(getDistance(instructions))
}
