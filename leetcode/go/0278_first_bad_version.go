package main

import (
	"fmt"
)

var versions []bool

func isBadVersion(v int) bool {
	return !versions[v]
}

func firstBadVersion(n int) int {
	start, end := 0, n
	for end-start > 1 {
		mid := start + (end-start)>>1
		if isBadVersion(mid) {
			end = mid
		} else {
			start = mid
		}
	}
	return end
}

func main() {
	versions = []bool{true, true, true, true, true, true, false, false}
	v := firstBadVersion(len(versions))
	fmt.Printf("First bad version: v%d\n", v)
}
