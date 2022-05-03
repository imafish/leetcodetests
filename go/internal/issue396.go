package leetcodetests

func maxRotateFunction(nums []int) int {
	length := len(nums)
	sum := 0
	f := 0
	for i, n := range nums {
		sum += n
		f += n * i
	}
	max := f

	for i := 1; i < length; i++ {
		newF := f + sum - length*nums[length-i]
		if newF > max {
			max = newF
		}
		f = newF
	}
	return max
}
