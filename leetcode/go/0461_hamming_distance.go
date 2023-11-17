package main

import (
	"fmt"
	"math/bits"
)

func hammingDistance(x int, y int) int {
	xor := x ^ y
	count := 0
	for xor != 0 {
		count += xor & 1
		xor >>= 1
	}
	return count
}

func hammingDistanceOnliner(x, y int) int {
	return bits.OnesCount(uint(x ^ y))
}

func main() {
	x := 1
	y := 2
	hd := hammingDistance(x, y)
	fmt.Printf("Hamming distance of (%d, %d) -> %d\n", x, y, hd)
}
