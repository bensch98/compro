package main

import (
	"fmt"
	"strconv"
)

func addDigits(num int) int {
	if num%9 == 0 && num != 0 {
		return 9
	}
	return num % 9
}

func addDigits2(num int) int {
	for {
		if num <= 9 {
			return num
		}
		sum := 0
		for _, i := range strconv.Itoa(num) {
			sum += int(i - '0')
		}
		num = sum
	}
}

func main() {
	// single digit cross sum
	sdcs := addDigits(38)
	fmt.Printf("Single digit cross sum: %d\n", sdcs)
}
