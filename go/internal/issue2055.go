package leetcodetests

func platesBetweenCandles(s string, queries [][]int) []int {
	candleIndex := -1
	plateIndex := 0
	data := make([][3]int, len(s))
	for i, c := range s {
		if c == '|' {
			candleIndex = i
		} else {
			data[i][0] = plateIndex
			plateIndex++
		}
		data[i][1] = candleIndex
	}
	candleIndex = -1
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '|' {
			candleIndex = i
		}
		data[i][2] = i
	}

	result := make([]int, len(queries))
	for i, q := range queries {
		left, right := data[q[0]][2], data[q[1]][1]
		if left == -1 || right == -1 || left+1 >= right {
			result[i] = 0
		} else {
			result[i] = data[right][0] - data[left+1][0]
		}
	}
	return result
}
