package leetcodetests

func binarySearch(nums []int, target int, isLowerBound bool) int {
	start, end := 0, len(nums)
	answer := end
	for start < end {
		mid := (start + end) / 2
		if (nums[mid] > target) || (isLowerBound && nums[mid] >= target) {
			answer = mid
			end = mid
		} else {
			start = mid + 1
		}
	}

	return answer
}

func searchRange(nums []int, target int) []int {
	left, right := binarySearch(nums, target, true), binarySearch(nums, target, false)-1
	if left <= right && right < len(nums) && nums[right] == target && nums[left] == target {
		return []int{left, right}
	}
	return []int{-1, -1}
}
