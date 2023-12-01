package main

import (
	"fmt"
)

func constructRectangle(area int) []int {
	l, w := area, 1
	for i := 1; i*i <= area; i++ {
		if area%i == 0 {
			l = i
			w = area / i
		}
	}
	if w > l {
		l, w = w, l
	}
	return []int{l, w}
}

func main() {
	area := 122122
	rectangle := constructRectangle(area)
	fmt.Printf("For area %d the rectangle is %v\n", area, rectangle)
}
