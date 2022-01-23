package leetcodetests

func lengthOfLongestSubstring(s string) int {
	result := 0
	headIndex := 0
	strlen := len(s)
	charData := make(map[byte]int)

	for i := 0; i < strlen; i++ {
		b := s[i]
		var maxLength int
		if charIndex, ok := charData[b]; ok && charIndex >= headIndex {
			maxLength = i - headIndex
			headIndex = charIndex + 1
		} else {
			maxLength = i - headIndex + 1
		}

		if maxLength > result {
			result = maxLength
		}
		charData[b] = i
	}

	return result
}
