package main

import (
	"fmt"
)

type NumArray struct {
	nums []int
}

func Constructor(nums []int) NumArray {
	n := NumArray{nums: nums}
	return n
}

func (this *NumArray) SumRange(left int, right int) int {
	sum := 0
	for _, n := range this.nums[left : right+1] {
		sum += n
	}
	return sum
}

func main() {
	nums := []int{-2, 0, 3, -5, 2, -1}
	obj := Constructor(nums)

	tests := [][]int{{0, 2}, {2, 5}, {0, 5}}
	for _, i := range tests {
		param := obj.SumRange(i[0], i[1])
		fmt.Printf("Range: %d\n", param)
	}
}
