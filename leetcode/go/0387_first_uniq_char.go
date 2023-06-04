package main

import (
	"fmt"
)

func firstUniqChar(s string) int {
	l := make([]int, 26)
	for _, c := range s {
		l[c-0x61]++
	}
	for i, c := range s {
		if l[c-0x61] == 1 {
			return i
		}
	}
	return -1
}

func main() {
	s := "leetcode"
	i := firstUniqChar(s)
	fmt.Printf("First unique character: %c at index %d\n", s[i], i)
}
