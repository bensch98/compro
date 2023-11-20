package main

import (
	"fmt"
	"math/bits"
)

func findComplement(num int) int {
	return (1<<(bits.Len(uint(num))) - 1) ^ num
}

func main() {
	num := 5
	fmt.Printf("Complement of %d is %d\n", num, findComplement(num))
}
