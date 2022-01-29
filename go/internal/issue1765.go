package leetcodetests

import "math"

func highestPeak(isWater [][]int) [][]int {
	iSize, jSize := len(isWater), len(isWater[0])
	height := make([][]int, iSize)
	queue := make([][2]int, 0)
	directions := [][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}

	for i := 0; i < iSize; i++ {
		height[i] = make([]int, jSize)
		for j := 0; j < jSize; j++ {
			if isWater[i][j] == 1 {
				height[i][j] = 0
				queue = append(queue, [2]int{i, j})
			} else {
				height[i][j] = math.MaxInt32
			}
		}
	}

	for len(queue) > 0 {
		pos := queue[0]
		queue = queue[1:]
		i, j := pos[0], pos[1]
		value := height[i][j] + 1

		for _, d := range directions {
			ii, jj := i+d[0], j+d[1]
			if ii >= 0 && ii < iSize && jj >= 0 && jj < jSize && height[ii][jj] == math.MaxInt32 {
				height[ii][jj] = value
				queue = append(queue, [2]int{ii, jj})
			}
		}
	}

	return height
}
