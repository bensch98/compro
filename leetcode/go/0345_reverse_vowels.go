package main

import (
	"fmt"
	"unicode"
)

func isVowel(b byte) bool {
	vowels := []byte{'a', 'e', 'i', 'o', 'u'}
	b = byte(unicode.ToLower(rune(b)))
	for _, v := range vowels {
		if b == v {
			return true
		}
	}
	return false
}

func reverseVowels(s string) string {
	b := []byte(s)
	for i, j := 0, len(b)-1; i < j; i, j = i+1, j-1 {
		for !isVowel(b[i]) && i < j {
			i++
		}
		for !isVowel(b[j]) && j > i {
			j--
		}
		if i < j {
			b[i], b[j] = b[j], b[i]
		}
	}
	return string(b)
}

func main() {
	s := "leetcode"
	fmt.Printf("Original: %s\n", s)
	s = reverseVowels(s)
	fmt.Printf("Reversed: %s\n", s)
}
