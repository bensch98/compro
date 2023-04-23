package main

import (
	"fmt"
	"strings"
)

func wordPattern(pattern string, s string) bool {
	p2w := map[byte]string{}
	words := strings.Fields(s)
	if len(words) != len(pattern) {
		return false
	}

	w2p := map[string]byte{}
	for i, w := range words {
		if val, ok := p2w[pattern[i]]; ok {
			if val != w {
				return false
			}
		} else {
			if _, ok := w2p[w]; ok {
				return false
			}
			p2w[pattern[i]] = w
			w2p[w] = pattern[i]
		}
	}
	return true
}

func main() {
	pattern := "abba"
	s := "dog cat cat dog"
	fmt.Printf("String \"%s\" matches pattern \"%s\": %t\n", pattern, s, wordPattern(pattern, s))
}
