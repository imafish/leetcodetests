package leetcodetests

func numberOfLines(widths []int, s string) []int {
	lines, current := 0, 0
	for _, r := range s {
		length := widths[r-'a']
		current += length
		if current > 100 {
			lines++
			current = length
		}
	}

	return []int{lines + 1, current}
}
