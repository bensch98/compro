package main

import (
	"fmt"
)

func strStr(haystack string, needle string) int {
	for i := 0; i <= len(haystack)-len(needle); i++ {
		if haystack[i:len(needle)+i] == needle {
			return i
		}
	}
	return -1
}

func main() {
	haystack := "mississippi"
	needle := "issip"
	idx := strStr(haystack, needle)
	fmt.Printf("%s occurs in %s at index %d\n", needle, haystack, idx)
}
