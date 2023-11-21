package main

import (
	"fmt"
	"strings"
)

func licenseKeyFormatting(s string, k int) string {
	s = strings.Replace(s, "-", "", -1)
	s = strings.ToUpper(s)
	mod := len(s) % k

	if mod == 0 {
		mod += k
	}
	for mod < len(s) {
		s = s[:mod] + "-" + s[mod:]
		mod += k + 1
	}
	return s
}

func main() {
	key := "2-5g-3-J"
	chars := 2
	formatted := licenseKeyFormatting(key, chars)
	fmt.Printf("Formatting %s into %d groups: %s\n", key, chars, formatted)
}
