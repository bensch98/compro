package main

import (
	"fmt"
)

func longestPalindrome(s string) int {
	var cnt [58]int
	for _, c := range s {
		cnt[c-0x0041]++
	}
	uneven := 0 // largest uneven number
	sum := 0
	for i := 0; i < len(cnt); i++ {
		if cnt[i]%2 == 0 {
			sum += cnt[i]
		} else {
			sum += cnt[i] - 1
			uneven = 1
		}
	}
	return sum + uneven
}

func main() {
	s := "abccccdd"
	fmt.Printf("Longest palindrome for \"%s\" is %d character(s) long.\n", s, longestPalindrome(s))
}
