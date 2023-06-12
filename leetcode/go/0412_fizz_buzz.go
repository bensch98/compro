package main

import (
	"fmt"
	"strconv"
)

func fizzBuzz(n int) []string {
	s := make([]string, n+1)
	for i := 1; i <= n; i++ {
		if i%5 == 0 && i%3 == 0 {
			s[i] = "FizzBuzz"
		} else if i%3 == 0 {
			s[i] = "Fizz"
		} else if i%5 == 0 {
			s[i] = "Buzz"
		} else {
			s[i] = strconv.Itoa(i)
		}
	}
	return s
}

func main() {
	res := fizzBuzz(15)
	fmt.Printf("%v\n", res)
}
