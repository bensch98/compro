package main

import (
	"fmt"
)

func reverseString(s []byte) {
	for i := 0; i < len(s)/2; i++ {
		tmp := s[i]
		s[i] = s[len(s)-i-1]
		s[len(s)-i-1] = tmp
	}
}

func reverseStringOneLiner(s []byte) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

func main() {
	s := []byte("hello")
	fmt.Println(string(s))
	reverseString(s)
	fmt.Println(string(s))
	reverseStringOneLiner(s)
	fmt.Println(string(s))
}
