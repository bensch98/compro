package main

import (
	"fmt"
)

func canConstruct(ransomNote string, magazine string) bool {
	letters := [26]int{}
	for _, c := range magazine {
		letters[c-0x61]++
	}
	for _, c := range ransomNote {
		if letters[c-0x61] == 0 {
			return false
		}
		letters[c-0x61]--
	}
	return true
}

func main() {
	r := "aaa"
	m := "aab"
	fmt.Printf("r: %s, m: %s -> can be constructed: %t\n", r, m, canConstruct(r, m))
}
