package leetcodetests

import (
	"sort"
)

func canReorderDoubled(arr []int) bool {
	data := make(map[int]int)
	for _, i := range arr {
		data[i]++
	}

	nums := make([]int, 0, len(data))
	for k := range data {
		nums = append(nums, k)
	}
	sort.Slice(nums, func(i, j int) bool {
		return abs(nums[i]) < abs(nums[j])
	})

	for _, i := range nums {
		if data[i] > data[i*2] {
			return false
		}
		data[i*2] -= data[i]
	}

	return true
}

func abs(i int) int {
	if i >= 0 {
		return i
	}
	return -i
}
