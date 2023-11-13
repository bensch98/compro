package main

import (
	"fmt"
	"sort"
)

func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)

	j := 0

	for _, v := range s {
		if j >= len(g) {
			break
		}

		if v >= g[j] {
			j++
		}
	}

	return j
}

func main() {
	g := []int{1, 2, 3}
	s := []int{1, 1}
	res := findContentChildren(g, s)
	fmt.Println(res)
}
