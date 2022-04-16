package leetcodetests

func maximumWealth(accounts [][]int) int {
	max := 0
	for _, account := range accounts {
		total := 0
		for _, v := range account {
			total += v
		}
		if total > max {
			max = total
		}
	}
	return max
}
