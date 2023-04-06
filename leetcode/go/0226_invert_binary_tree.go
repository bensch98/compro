package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func invertTree(root *TreeNode) *TreeNode {
	if root != nil {
		root.Left, root.Right = invertTree(root.Right), invertTree(root.Left)
	}
	return root
}

func printBtree(root *TreeNode) {
	fmt.Printf("[")
	preorder(root)
	fmt.Printf("]\n")
}

func preorder(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	fmt.Printf("%d, ", root.Val)
	preorder(root.Left)
	preorder(root.Right)
	return root
}

func main() {
	// testcase
	var btree *TreeNode = &TreeNode{
		4,
		&TreeNode{
			2,
			&TreeNode{1, nil, nil},
			&TreeNode{3, nil, nil},
		},
		&TreeNode{
			7,
			&TreeNode{6, nil, nil},
			&TreeNode{9, nil, nil},
		},
	}

	// invert
	printBtree(btree)
	btree = invertTree(btree)
	printBtree(btree)
}
