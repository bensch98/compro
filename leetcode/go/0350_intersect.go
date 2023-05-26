package main

import (
	"fmt"
)

func intersect(nums1 []int, nums2 []int) []int {
	cnt := [1001]int{}
	res := make([]int, 0, len(nums1))
	for _, i := range nums1 {
		cnt[i]++
	}
	for _, i := range nums2 {
		if cnt[i] > 0 {
			res = append(res, i)
			cnt[i]--
		}
	}
	return res
}

func main() {
	nums1 := []int{4, 9, 5}
	nums2 := []int{9, 4, 9, 8, 4}
	i := intersect(nums1, nums2)

	fmt.Printf("Intersection: %v\n", i)
}
