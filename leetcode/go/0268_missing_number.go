package main

import (
	"fmt"
)

func missingNumbers(nums []int) int {
	gauss := len(nums) * (len(nums) + 1) / 2
	for _, n := range nums {
		gauss -= n
	}
	return gauss
}

func missingNumbers2(nums []int) int {
	sum := 0
	goal := 0
	for idx, num := range nums {
		goal += idx
		sum += num
	}
	return goal + len(nums) - sum
}

func main() {
	nums := []int{3, 0, 1}
	num := missingNumbers(nums)
	fmt.Printf("Missing number: %d\n", num)
}
