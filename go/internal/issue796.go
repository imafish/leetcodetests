package leetcodetests

func rotateString(s string, goal string) bool {
	lens := len(s)
	if lens != len(goal) {
		return false
	}

	if s == goal {
		return true
	}

	for i := 1; i < lens; i++ {
		subs1, subs2 := s[0:i], s[i:lens]
		if subs2 == goal[0:lens-i] && subs1 == goal[lens-i:lens] {
			return true
		}
	}
	return false
}
