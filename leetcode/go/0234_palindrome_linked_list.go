package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func isPalindrome(head *ListNode) bool {
	slow, fast, stack := head, head, make([]int, 0)
	for fast != nil && fast.Next != nil {
		stack = append(stack, slow.Val)
		slow = slow.Next
		fast = fast.Next.Next
	}
	if fast != nil && fast.Next == nil {
		slow = slow.Next
	}
	for slow != nil {
		tmp := stack[len(stack)-1]
		if slow.Val != tmp {
			return false
		}
		stack = stack[:len(stack)-1]
		slow = slow.Next
	}
	return true
}

func main() {
	// testcase
	ll := &ListNode{
		4,
		&ListNode{
			6,
			&ListNode{
				4,
				nil,
			},
		},
	}

	fmt.Printf("LinkedList is a palindrome: %t\n", isPalindrome(ll))
}
