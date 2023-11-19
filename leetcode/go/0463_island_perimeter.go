package main

import (
	"fmt"
)

const (
	water = 0
	land  = 1
)

func islandPerimeter(grid [][]int) int {
	perim := 0
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == land {
				if j-1 < 0 || grid[i][j-1] == water {
					perim++
				}
				if j+1 >= len(grid[i]) || grid[i][j+1] == water {
					perim++
				}
				if i-1 < 0 || grid[i-1][j] == water {
					perim++
				}
				if i+1 >= len(grid) || grid[i+1][j] == water {
					perim++
				}
			}
		}
	}
	return perim
}

func main() {
	grid := [][]int{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}}
	fmt.Printf("perimeter: %d\n", islandPerimeter(grid))
}
