package main

import (
	"fmt"
	"math/big"
)

func padWithZeros(s string, length int) string {
	format := fmt.Sprintf("%%0%ds", length)
	return fmt.Sprintf(format, s)
}

func addStrings2(num1 string, num2 string) string {
	// determine longer string
	maxLen := len(num1)
	if len(num2) > len(num1) {
		maxLen = len(num2)
	}

	// pad with zeros
	num1 = padWithZeros(num1, maxLen)
	num2 = padWithZeros(num2, maxLen)

	// num1 + num2
	var res string = ""
	var carry int = 0
	for i := len(num1) - 1; i >= 0; i-- {
		sum := int(num1[i]-0x30) + int(num2[i]-0x30) + carry
		if sum > 9 {
			carry = 1
		} else {
			carry = 0
		}
		res = fmt.Sprintf("%d%s", sum%10, res)
	}

	if carry == 1 {
		res = fmt.Sprintf("1%s", res)
	}

	return res
}

func addStrings(num1 string, num2 string) string {
	bigIntNum1, _ := new(big.Int).SetString(num1, 10)
	bigIntNum2, _ := new(big.Int).SetString(num2, 10)
	sum := new(big.Int).Add(bigIntNum1, bigIntNum2)
	return sum.String()
}

func main() {
	num1, num2 := "19", "123"
	fmt.Printf("%s + %s = %s\n", num1, num2, addStrings(num1, num2))
	fmt.Printf("%s + %s = %s\n", num1, num2, addStrings2(num1, num2))
}
