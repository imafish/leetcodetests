package leetcodetests

import "sort"

func combinationSum(candidates []int, target int) [][]int {
	result := make([][]int, 0)

	sort.Slice(candidates, func(i, j int) bool { return candidates[i] < candidates[j] })
	c := []int{0}
	currentTotal := candidates[0]

	for len(c) > 0 {
		if currentTotal == target {
			result = append(result, generateResult(c, candidates))
		}
		if currentTotal >= target {
			if len(c) == 1 {
				break
			}

			currentTotal -= candidates[c[len(c)-1]]
			c = c[0 : len(c)-1]

			lastPos := c[len(c)-1]
			for lastPos == len(candidates)-1 {
				currentTotal -= candidates[lastPos]
				c = c[0 : len(c)-1]
				if len(c) == 0 {
					break
				}
				lastPos = c[len(c)-1]
			}
			if len(c) == 0 {
				break
			}
			c[len(c)-1] += 1
			currentTotal += candidates[c[len(c)-1]] - candidates[c[len(c)-1]-1]
		} else {
			c = append(c, c[len(c)-1])
			currentTotal += candidates[c[len(c)-1]]
		}
	}
	return result
}

func generateResult(c []int, candidates []int) []int {
	result := make([]int, len(c))
	for i, j := range c {
		result[i] = candidates[j]
	}
	return result
}
