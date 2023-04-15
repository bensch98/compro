package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func binaryTreePathsWithString(root *TreeNode, s string) []string {
	if root == nil {
		return []string{}
	}
	if root.Left == nil && root.Right == nil {
		return []string{fmt.Sprintf("%s%d", s, root.Val)}
	}
	left := binaryTreePathsWithString(root.Left, fmt.Sprintf("%s%d->", s, root.Val))
	right := binaryTreePathsWithString(root.Right, fmt.Sprintf("%s%d->", s, root.Val))

	return append(left, right...)
}

func binaryTreePaths(root *TreeNode) []string {
	return binaryTreePathsWithString(root, "")
}

func main() {
	bt := &TreeNode{
		1,
		&TreeNode{
			2,
			nil,
			&TreeNode{
				5, nil, nil,
			},
		},
		&TreeNode{3, nil, nil},
	}
	fmt.Println(binaryTreePaths(bt))
}
