package main

import (
	"fmt"
	"strings"
)

func countSegments(s string) int {
	s = strings.TrimSpace(s)
	segments := strings.Split(s, " ")
	count := 0
	for _, segment := range segments {
		if segment != "" {
			count++
		}
	}
	return count
}

func main() {
	s := "Hello, my name is John"
	count := countSegments(s)
	fmt.Printf("Number of segments: %d\n", count)
}
