package main

import (
	"fmt"
)

func twoSum(nums []int, target int) []int {
	num2idx := make(map[int]int)
	var search int
	for i, num := range(nums) {
		search = target - num
		if val, ok := num2idx[search]; ok {
			return []int{i, val}
		}
		num2idx[num] = i
	}
	return []int{-1, -1}
}

func main() {
	nums := []int{2, 7, 11, 15}
	target := 26
	res := twoSum(nums, target)
	fmt.Println(res[0], res[1])
}
