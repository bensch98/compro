package main

import (
	"fmt"
)

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	sc := [26]int{}
	tc := [26]int{}
	for i := range s {
		sc[s[i]-'a']++
		tc[t[i]-'a']++
	}
	return sc == tc
}

func isAnagram2(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	counts := map[rune]int{}
	for _, l := range s {
		if _, ok := counts[l]; ok {
			counts[l]++
		} else {
			counts[l] = 1
		}
	}

	for _, l := range t {
		if _, ok := counts[l]; ok && counts[l] > 0 {
			fmt.Println(l, counts[l])
			counts[l]--
		} else {
			return false
		}
	}
	return true
}

func main() {
	s, t := "anagram", "nagaram"
	fmt.Printf("s: %s, t: %s -> valid anagram: %t\n", s, t, isAnagram(s, t))
}
