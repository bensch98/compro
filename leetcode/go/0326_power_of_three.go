package main

import (
	"fmt"
)

func isPowerOfThreeConstantTime(n int) bool {
	return (n > 0) && (3486784401%n == 0)
}

func isPowerOfThree(n int) bool {
	if n == 0 {
		return false
	}
	for n%3 == 0 {
		n /= 3
	}
	return n == 1
}

func main() {
	x := 27
	fmt.Printf("%d is a power of three: %t\n", x, isPowerOfThree(x))
	fmt.Printf("%d is a power of three: %t\n", x, isPowerOfThreeConstantTime(x))
}
