package leetcodetests

import "math"

func largestPalindrome(n int) int {
	if n == 1 {
		return 9
	}

	for max := int(math.Pow10(n)) - 1; ; max-- {
		leftPart, rightPart := max, 0
		for leftPart > 0 {
			rightPart *= 10
			rightPart += leftPart % 10
			leftPart /= 10
		}
		palidrome := int64(leftPart)*int64(math.Pow10(n)) + int64(rightPart)
		for x := int64(math.Pow10(n)) - 1; x*x > palidrome; x-- {
			if palidrome%x == 0 {
				return int(palidrome) % 1337
			}
		}
	}
}
