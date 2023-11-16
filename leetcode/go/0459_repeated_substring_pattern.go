package main

import (
	"fmt"
	"strings"
)

func repeatedSubstringPatternSlow(s string) bool {
	if s == "" {
		return false
	}

	for i := 1; i < len(s); i++ {
		if len(s)%i == 0 {
			// pattern logic
			tmp := s[0:i]
			res := ""
			fmt.Println(tmp)
			fmt.Println(res)

			for j := 0; j < (len(s) / len(tmp)); j++ {
				res += tmp
				fmt.Println(res)
			}
			fmt.Println(res, s)
			if res == s {
				return true
			}
		}
	}
	return false
}

func repeatedSubstringPatternShort(s string) bool {
	t := s + s
	return strings.Contains(t[1:len(t)-1], s)
}

func repeatedSubstringPattern(s string) bool {
	for i := len(s) / 2; i >= 1; i-- {
		if len(s)%i != 0 {
			continue
		}
		for j := range s {
			if s[j] != s[j+i] {
				break
			}
			if j == len(s)-i-1 {
				return true
			}
		}
	}
	return false
}

func main() {
	s := "abab"
	fmt.Printf("String '%s' can be constructed by repeated pattern: %t\n", s, repeatedSubstringPattern(s))
}
