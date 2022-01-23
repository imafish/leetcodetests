package leetcodetests

// https://leetcode-cn.com/circle/discuss/tLpGoM/

func group(people []int, k int, maxDiff int) int {
	return 0
}

func isValid(s string) bool {
	l := len(s)
	if l == 0 {
		return true
	}
	if l == 1 {
		return false
	}

	if s[0] == s[l-1] && isValid(s[1:l-1]) {
		return true
	}

	// split
	return false
}
