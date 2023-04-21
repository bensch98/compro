package main

import (
	"fmt"
)

func moveZeros(nums []int) {
	lastNonZero := 0
	for i := range nums {
		if nums[i] == 0 {
			nums[i], nums[lastNonZero] = nums[lastNonZero], nums[i]
			lastNonZero++
		}
	}
}

func moveZeros1(nums []int) {
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] == 0 {
			for j := i + 1; j < len(nums); j++ {
				if nums[j] != 0 {
					tmp := nums[i]
					nums[i] = nums[j]
					nums[j] = tmp
					break
				}
			}
		}
	}
}

func printSlice(nums []int) {
	for _, n := range nums {
		fmt.Printf("%d, ", n)
	}
	fmt.Printf("\n")
}

func main() {
	nums := []int{0, 1, 0, 3, 12}
	printSlice(nums)
	moveZeros(nums)
	printSlice(nums)
}
