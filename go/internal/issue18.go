package leetcodetests

import "sort"

func fourSum(nums []int, target int) [][]int {
	sz := len(nums)
	result := make([][]int, 0)
	if sz < 4 {
		return result
	}

	sort.Slice(nums, func(a int, b int) bool { return nums[a] < nums[b] })

	for a := 0; a < sz-3; a++ {
		na := nums[a]
		if a > 0 && na == nums[a-1] {
			continue
		}
		if int64(na)+int64(nums[a+1])+int64(nums[a+2])+int64(nums[a+3]) > int64(target) {
			break
		}
		if na+nums[sz-1]+nums[sz-2]+nums[sz-3] < target {
			continue
		}

		for b := a + 1; b < sz-2; b++ {
			nb := nums[b]
			if b > a+1 && nb == nums[b-1] {
				continue
			}
			if na+nb+nums[b+1]+nums[b+2] > target {
				break
			}

			c := b + 1
			d := sz - 1
			for c < d {
				nc := nums[c]
				nd := nums[d]
				sum := na + nb + nc + nd
				var moveC, moveD bool
				if sum == target {
					result = append(result, []int{na, nb, nc, nd})
					moveC = true
					moveD = true
				} else if sum < target {
					moveC = true
				} else {
					moveD = true
				}

				if moveC {
					for c = c + 1; c < d && nc == nums[c]; c++ {
					}
					if c == d {
						break
					}
				}
				if moveD {
					for d = d - 1; c < d && nd == nums[d]; d-- {
					}
					if c == d {
						break
					}
				}
			}
		}
	}

	return result
}
