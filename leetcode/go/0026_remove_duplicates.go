package main

import (
	"fmt"
)

func removeDuplicates(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	if len(nums) == 2 {
		if nums[0] == nums[1] {
			return 1
		} else {
			return 2
		}
	}

	i := 0
	for j := i + 1; j < len(nums); j++ {
		if nums[j] >= nums[i+1] && nums[j] != nums[i] {
			i++
			nums[i] = nums[j]
		}
	}
	return i + 1
}

func main() {
	// testcase
	var v []int = []int{-420, -69, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 69, 420, 420}
	var removed int = removeDuplicates(v)
	fmt.Printf("First %d numbers are unique and ordered.\n", removed)

	// print vector
	for _, i := range v {
		fmt.Printf("%d, ", i)
	}
	fmt.Printf("\n")
}
