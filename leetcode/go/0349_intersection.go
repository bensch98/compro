package main

import (
	"fmt"
)

func intersection(nums1 []int, nums2 []int) []int {
	set := make(map[int]bool)
	res := []int{}
	for _, i := range nums1 {
		set[i] = true
	}
	for _, i := range nums2 {
		if _, ok := set[i]; ok && set[i] {
			res = append(res, i)
			set[i] = false
		}
	}
	return res
}

func main() {
	nums1 := []int{4, 9, 5}
	nums2 := []int{9, 4, 9, 8, 4}
	i := intersection(nums1, nums2)

	fmt.Printf("Intersection: %v\n", i)
}
