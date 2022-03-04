package leetcodetests

func subArrayRanges(nums []int) int64 {
	var result int64 = 0

	min, max := 0, 0

	for i, l := range nums {
		min, max = l, l
		for _, r := range nums[i+1:] {
			if r < min {
				min = r
			}
			if r > max {
				max = r
			}
			result += int64(max - min)
		}
	}
	return result
}
