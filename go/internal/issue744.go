package leetcodetests

func nextGreatestLetter(letters []byte, target byte) byte {
	if target == 'z' {
		target = 'a' - 1
	}

	for _, k := range letters {
		if k > target {
			return k
		}
	}
	return letters[0]
}
