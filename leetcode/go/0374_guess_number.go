package main

import (
	"fmt"
)

var secret int = 52342

func guess(num int) int {
	if num > secret {
		return -1
	} else if num < secret {
		return 1
	} else {
		return 0
	}
}

func guessNumber(n int) int {
	lo, hi := 1, n
	mid := (lo + hi) / 2
	for {
		switch guess(mid) {
		case -1:
			hi = mid - 1
		case 1:
			lo = mid + 1
		default:
			return mid
		}
		mid = (hi + lo) / 2
		fmt.Println(mid)
	}
}

func main() {
	n := 2 << 31
	pick := guessNumber(n)
	fmt.Printf("Picked number: %d\n", pick)
}
