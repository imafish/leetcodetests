package leetcodetests

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}

	// calculate width of the matrix
	strlen := len(s)
	unitCharCount := numRows*2 - 2
	numUnits := strlen / unitCharCount
	if strlen%unitCharCount > 0 {
		numUnits++
	}

	buff := make([]byte, strlen)

	// first row
	i := 0

	for j := 0; j < strlen; i, j = i+1, (i+1)*unitCharCount {
		buff[i] = s[j]
	}

	// middle row
	for row := 1; row < numRows-1; row++ {
		for k := 0; ; k++ {
			j := (k/2)*unitCharCount + row
			if j >= strlen {
				break
			}
			buff[i] = s[j]
			i++

			k++
			j = (k/2)*unitCharCount + unitCharCount - row
			if j >= strlen {
				break
			}
			buff[i] = s[j]
			i++
		}
	}

	// last row
	for k, j := 0, numRows-1; j < strlen; k, j = k+1, (k+1)*unitCharCount+numRows-1 {
		buff[i] = s[j]
		i++
	}

	return string(buff)
}
