package main

import (
	"fmt"
)

func findMaxConsecutiveOnes(nums []int) int {
	var res int
	counter := 0

	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			if counter > res {
				res = counter
			}
			counter = 0
		} else {
			counter++
		}
	}
	if counter > res {
		res = counter
	}
	return res
}

func main() {
	nums := []int{1, 1, 0, 1, 1, 1}
	n := findMaxConsecutiveOnes(nums)
	fmt.Printf("Maximum number of consecutive ones: %d\n", n)
}
