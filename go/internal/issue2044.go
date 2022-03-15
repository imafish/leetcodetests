package leetcodetests

func countMaxOrSubsets(nums []int) int {
	max := 0
	for _, i := range nums {
		max = max | i
	}

	indexes := make([][2]int, 0)
	sum := 0
	count := 0
	sz := len(nums)
	i := 0

	advance := func() bool {
		last := indexes[len(indexes)-1]
		indexes = indexes[:len(indexes)-1]
		if last[0] == sz-1 {
			if len(indexes) == 0 {
				return false
			}
			last = indexes[len(indexes)-1]
			indexes = indexes[:len(indexes)-1]
		}
		i = last[0] + 1
		sum = last[1]
		return true
	}

	for {
		indexes = append(indexes, [2]int{i, sum})
		sum = sum | nums[i]

		if sum == max {
			count += 1 << (sz - i - 1)

			if !advance() {
				break
			}
		} else if i < sz-1 {
			i++
		} else if !advance() {
			break
		}
	}

	return count
}
