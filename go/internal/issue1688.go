package leetcodetests

func numberOfMatches(n int) int {
	total := 0
	for n > 1 {
		total += n / 2
		n = n/2 + n%2
	}
	return total
}
