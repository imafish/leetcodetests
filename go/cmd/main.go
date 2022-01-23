package main

import "fmt"

func sliceOperation(s []int) []int {
	s[0] = s[0] + 1
	s = append(s, 99)

	return s
}

func main() {
	s := []int{1, 2, 3, 4}

	t := sliceOperation(s)

	fmt.Printf("%v\n", s)
	fmt.Printf("%v\n", t)
}
