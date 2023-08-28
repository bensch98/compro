package main

import (
	"fmt"
)

func findDisappearedNumbers(nums []int) []int {
	n := len(nums)
	mark := make([]bool, n+1)
	for _, num := range nums {
		mark[num] = true
	}
	var result []int
	for i := 1; i <= n; i++ {
		if !mark[i] {
			result = append(result, i)
		}
	}
	return result
}

func main() {
	nums := []int{4, 3, 2, 7, 8, 2, 3, 1}
	result := findDisappearedNumbers(nums)
	fmt.Printf("Missing numbers: %v\n", result)
}
