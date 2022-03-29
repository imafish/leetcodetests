package leetcodetests

func hasAlternatingBits(n int) bool {
	bit := n & 1
	n = n >> 1

	for n > 0 {
		b := n & 1
		if b == bit {
			return false
		}
		n = n >> 1
		bit = b
	}
	return true
}
