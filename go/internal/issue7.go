package leetcodetests

import "math"

func reverse(x int) int {

	isPositive := (x > 0)
	var result int32 = 0

	// convert to positive number
	// edge case: x = -2^31
	if x == -(2 ^ 31) {
		return 0
	}
	if !isPositive {
		x = -x
	}

	const edge = math.MaxInt32 / 10
	const edgeLeft = 7

	for digit := int32(x % 10); x > 0; x, digit = x/10, int32((x/10)%10) {
		if result > edge || (result == edge && digit > edgeLeft) {
			return 0
		}

		result = result*10 + digit
	}

	if !isPositive {
		result = -result
	}

	return int(result)
}
