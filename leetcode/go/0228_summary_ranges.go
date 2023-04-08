package main

import (
	"fmt"
	"strconv"
)

func summaryRanges(nums []int) []string {
	n := len(nums)
	ranges := []string{}
	tmp := ""
	var j int

	for i := 0; i < n; i++ {
		j = i
		for {
			if !(j + 1 < n && nums[j+1] == nums[j] + 1) {
				break
			}
			j++
		}
		if j > i {
			tmp = fmt.Sprintf("%d->%d", nums[i], nums[j])
		} else {
			tmp = strconv.Itoa(nums[i])
		}
		ranges = append(ranges, tmp)
		tmp = ""
		i = j
	}
	return ranges
}

func main() {
	// testcase
	nums := []int{0, 2, 3, 4, 6, 8, 9}

	ranges := summaryRanges(nums)
	for _, r := range ranges {
		fmt.Printf("%s, ", r)
	}
	fmt.Println()
}
