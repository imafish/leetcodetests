package leetcodetests

import "sort"

func numberOfWeakCharacters(properties [][]int) int {
	sort.Slice(properties, func(i int, j int) bool {
		if properties[i][0] == properties[j][0] {
			return properties[i][1] < properties[j][1]
		} else {
			return properties[i][0] > properties[j][0]
		}
	})

	cnt := 0
	maxDef := 0
	for _, p := range properties {
		if p[1] < maxDef {
			cnt++
		} else {
			maxDef = p[1]
		}
	}

	return cnt
}
