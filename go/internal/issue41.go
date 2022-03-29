package leetcodetests

func firstMissingPositive(nums []int) int {
	length := len(nums)

	for i, n := range nums {
		if n <= 0 {
			nums[i] = length + 1
		}
	}
	for _, n := range nums {
		if n > 0 && n <= length && nums[n-1] > 0 {
			nums[n-1] = -nums[n-1]
		}
	}

	for i, n := range nums {
		if n < 0 {
			return i + 1
		}
	}
	return length + 1
}
