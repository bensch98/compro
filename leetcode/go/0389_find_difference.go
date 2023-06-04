package main

import (
	"fmt"
)

func findTheDifference(s string, t string) byte {
	var sum byte = 0
	for i := 0; i < len(s); i++ {
		sum -= s[i]
		sum += t[i]
	}
	sum += t[len(t)-1]
	return sum
}

func main() {
	s, t := "abcd", "abcde"
	fmt.Printf("%c is the letter that was added\n", findTheDifference(s, t))
}
