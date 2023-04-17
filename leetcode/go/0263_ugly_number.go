package main

import (
	"fmt"
)

func isUgly(n int) bool {
	if n <= 0 {
		return false
	}
	for n%2 == 0 || n%3 == 0 || n%5 == 0 {
		if n%2 == 0 {
			n /= 2
		}
		if n%3 == 0 {
			n /= 3
		}
		if n%5 == 0 {
			n /= 5
		}
	}
	if n != 1 && n != 2 && n != 3 && n != 5 {
		return false
	}
	return true
}

func isUgly2(n int) bool {
	if n < 1 {
		return false
	}
	c := make(chan int, 3)
	for _, factor := range [3]int{2, 3, 5} {
		go func(n int, factor int) {
			for ; n%factor == 0; n /= factor {
			}
			c <- n
		}(n, factor)
	}
	return <-c*<-c*<-c == n*n
}

func main() {
	for i := 0; i < 20; i++ {
		fmt.Printf("%d is ugly: \t%t\n", i, isUgly(i))
	}
}
