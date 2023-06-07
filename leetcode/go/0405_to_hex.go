package main

import (
	"fmt"
)

func toHex(num int) string {
	return fmt.Sprintf("%x", uint32(num))
}

func main() {
	i := -1
	fmt.Printf("Dec: %d -> Hex: %s\n", i, toHex(i))
}
