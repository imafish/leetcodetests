package leetcodetests

func selfDividingNumbers(left int, right int) []int {
	result := make([]int, 0)
	for i := left; i <= right; i++ {
		if isDividingNumbers(i) {
			result = append(result, i)
		}
	}
	return result
}

func isDividingNumbers(n int) bool {
	current := n
	for current > 0 {
		div := current % 10
		if div == 0 || n%div != 0 {
			return false
		}
		current = current / 10
	}
	return true
}
