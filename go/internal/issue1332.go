package leetcodetests

func removePalindromeSub(s string) int {
	l := len(s)

	if l == 0 {
		return 0
	}

	for i := 0; i < l-1; {
		if s[i] != s[l-1] {
			return 2
		}
		i++
		l--
	}

	return 1
}
