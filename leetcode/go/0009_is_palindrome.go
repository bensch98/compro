package main

import (
	"fmt"
)

func isPalindrome(x int) bool {
	var rev int
	tmp := x
	for tmp > 0 {
		rev = rev*10 + tmp%10
		tmp /= 10
	}
	return x == rev
}

func msg(x int, b bool) string {
	if b {
		return fmt.Sprintf("%d is a palindrome", x)
	}
	return fmt.Sprintf("%d is not a palindrome", x)
}

func main() {
	x := 121
	y := isPalindrome(x)
	fmt.Println(msg(x, y))
}
