package main

import (
	"fmt"
)

func isPowerOfTwo(n int) bool {
	if n == 0 {
		return false
	}
	return n&(n-1) == 0
}

func isPowerOfTwo1(n int) bool {
	mod := 0
	if n == 0 {
		return false
	}
	for {
		if n == 1 || mod != 0 {
			break
		}
		mod = n % 2
		n /= 2
	}
	return mod == 0
}

func main() {

	tests := []int{0, 1, 3, 5, 8, 16, 1024}
	for _, i := range tests {
		fmt.Printf("%d is a power of 2: %t\n", i, isPowerOfTwo(i))
	}
}
