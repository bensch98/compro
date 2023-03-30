package main

import (
	"fmt"
)

func isValid(s string) bool {
	pairs := map[rune]rune{
		'(': ')',
		'[': ']',
		'{': '}',
	}
	stack := []rune{}
	for _, r := range s {
		if _, ok := pairs[r]; ok {
			stack = append(stack, r)
		} else if len(stack) == 0 || pairs[stack[len(stack)-1]] != r {
			return false
		} else {
			stack = stack[:len(stack)-1]
		}
	}
	return len(stack) == 0
}

func main() {
	tests := []string{
		"()",
		"()[]{}",
		"(]",
		"({}){([])}",
	}
	for _, test := range tests {
		fmt.Printf("Test case: %s\n", test)
		fmt.Printf("Valid: %t\n", isValid(test))
	}
}
