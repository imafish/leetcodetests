package leetcodetests

func jump(nums []int) int {
	length := len(nums)
	jumps := make([]int, length)
	for i, j := range nums {
		k := i + j
		if k >= length {
			k = length - 1
		}
		for l := i + 1; l <= k; l++ {
			newJump := jumps[i] + 1
			if jumps[l] == 0 || jumps[l] > newJump {
				jumps[l] = newJump
			}
		}
	}

	return jumps[length-1]
}
