package main

import (
	"fmt"
	"math/rand"
	"time"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var cur *ListNode = &ListNode{}
	var head *ListNode = cur

	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			cur.Next = l1
			l1 = l1.Next
		} else {
			cur.Next = l2
			l2 = l2.Next
		}
		cur = cur.Next
	}

	if l1 != nil {
		cur.Next = l1
	} else {
		cur.Next = l2
	}
	return head.Next
}

func printll(ll *ListNode) {
	for ll != nil {
		fmt.Println(ll.Val)
		ll = ll.Next
	}
}

func getRand(beg int, end int) int {
	s1 := rand.NewSource(time.Now().UnixNano())
	r1 := rand.New(s1)
	return r1.Intn(end)%((end-beg)+1) + beg
}

func createll(ll *ListNode) {
	var cur *ListNode = ll
	var (
		max int = 10
		tmp int = 0
		r   int = getRand(0, 20)
	)

	for i := 0; i < r; i++ {
		tmp = getRand(tmp, max)
		cur.Next = new(ListNode)
		cur.Next.Val = tmp
		cur = cur.Next
		max += 10
	}
}

func main() {
	// testcase
	var (
		l1 ListNode
		l2 ListNode
	)

	// create linked lists
	createll(&l1)
	printll(&l1)
	createll(&l2)
	printll(&l2)
	var lmerged *ListNode = mergeTwoLists(&l1, &l2)

	// print result
	fmt.Printf("\nMerged:\n")
	printll(lmerged)
}
