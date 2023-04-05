package main

import (
	"fmt"
)

func removeElement(nums []int, val int) int {
	var i int
	for k, v := range nums {
		if v != val {
			nums[i] = nums[k]
			i++
		}
	}
	return i
}

func main() {
	// testcase
	var v []int = []int{0, 1, 2, 2, 3, 0, 4, 2}
	var val int = 2

	for _, j := range v {
		fmt.Printf("%d, ", j)
	}
	fmt.Printf("\n")

	var removed int = removeElement(v, val)
	for _, j := range v {
		fmt.Printf("%d, ", j)
	}
	fmt.Printf("\n")
	fmt.Printf("First %d elements are correct.\n", removed)
}
