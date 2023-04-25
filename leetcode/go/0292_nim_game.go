package main

import (
	"fmt"
)

func canWinNim(n int) bool {
	return n%4 != 0
}

func main() {
	stones := 6
	fmt.Printf("Can win Nim game: %t\n", canWinNim(stones))
}
