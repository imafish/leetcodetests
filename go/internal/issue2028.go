package leetcodetests

func missingRolls(rolls []int, mean int, n int) []int {
	m := len(rolls)
	total := mean * (m + n)
	current := 0
	for _, i := range rolls {
		current += i
	}
	remaining := total - current
	if remaining < n || remaining > 6*n {
		return make([]int, 0)
	}

	avg := remaining / n
	remainder := remaining % n

	result := make([]int, n)
	for i := 0; i < remainder; i++ {
		result[i] = avg + 1
	}
	for i := remainder; i < n; i++ {
		result[i] = avg
	}
	return result
}
