package leetcodetests

func shortestToChar(s string, c byte) []int {
	length := len(s)
	result := make([]int, length)
	zeros := make([]int, 0, length)

	for i := range result {
		if s[i] == c {
			result[i] = 0
			zeros = append(zeros, i)
		} else {
			result[i] = -1
		}
	}

	found := true
	arm := 1
	for found {
		found = false
		for _, i := range zeros {
			idx := i - arm
			if idx >= 0 && result[idx] == -1 {
				result[idx] = arm
				found = true
			}

			idx = i + arm
			if idx < length && result[idx] == -1 {
				result[idx] = arm
				found = true
			}
		}
		arm++
	}

	return result
}
