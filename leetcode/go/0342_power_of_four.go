package main

import (
	"fmt"
)

func isPowerOfFourConstantTime(n int) bool {
	return n > 0 && n&(n-1) == 0 && (n-1)%3 == 0
}

func isPowerOfFour(n int) bool {
	if n < 1 {
		return false
	}
	for n%4 == 0 {
		n /= 4
	}
	return n == 1
}

func main() {
	x := 16
	fmt.Printf("%d is a power of four: %t\n", x, isPowerOfFour(x))
	fmt.Printf("%d is a power of four: %t\n", x, isPowerOfFourConstantTime(x))
}
