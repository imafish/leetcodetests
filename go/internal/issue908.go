package leetcodetests

func smallestRangeI(nums []int, k int) int {
	min, max := 10000, 0
	for _, i := range nums {
		if i < min {
			min = i
		}
		if i > max {
			max = i
		}
	}

	if max-min <= k*2 {
		return 0
	} else {
		return max - min - k*2
	}
}
