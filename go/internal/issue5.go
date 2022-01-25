package leetcodetests

func longestPalindrome(s string) string {
	strlen := len(s)

	if strlen < 2 {
		return s
	}

	data := make([][]bool, strlen)
	for i := range data {
		data[i] = make([]bool, strlen)
	}

	for i := 0; i < strlen; i++ {
		data[i][i] = true
	}

	finalI, finalJ := 0, 0

	for length := 2; length <= strlen; length++ {
		for i := 0; i <= strlen-length; i++ {
			j := i + length - 1

			if s[i] != s[j] {
				data[i][j] = false
			} else {
				if length == 2 {
					data[i][j] = true
				} else {
					data[i][j] = data[i+1][j-1]
				}
			}

			if data[i][j] {
				finalI, finalJ = i, j
			}
		}
	}

	return s[finalI : finalJ+1]
}
