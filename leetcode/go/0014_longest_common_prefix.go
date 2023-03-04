package main

import (
	"fmt"
)

func longestCommonPrefix(strs []string) string {
	p := strs[0]
	for _, s := range strs {
		i := 0
		for ; i < len(s) && i < len(p) && p[i] == s[i]; i++ {
		}
		p = p[:i]
	}
	return p
}

func main() {
	tests := [][]string{
		{"flower", "flow", "flight"},
		{"dog", "racecar", "car"},
		{""},
		{"a"},
	}
	for _, strs := range tests {
		fmt.Println(longestCommonPrefix(strs))
	}
}
