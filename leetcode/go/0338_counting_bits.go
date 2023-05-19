package main

import (
	"fmt"
)

func countBits(n int) []int {
	res := make([]int, n+1)
	for i := 1; i <= n; i++ {
		res[i] = res[i/2] + i%2
	}
	return res
}

func countBitsSlow(n int) []int {
	counts := []int{}
	for i := 0; i <= n; i++ {
		j := i
		count := 0
		for j > 0 {
			if j&1 == 1 {
				count++
			}
			j >>= 1
		}
		counts = append(counts, count)
	}
	return counts
}

func main() {
	x := 5
	bits1 := countBits(x)
	bits2 := countBitsSlow(x)
	fmt.Println("Dec\tBin\tSetBits\tSetBits")
	for i := 0; i < len(bits1); i++ {
		fmt.Printf("%d\t0b%b\t%d\t%d\n", i, i, bits1[i], bits2[i])
	}
}
