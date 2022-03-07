package leetcodetests

import "strings"

func convertToBase7(num int) string {
	if num == 0 {
		return "0"
	}
	var sb strings.Builder
	isNegative := false
	if num < 0 {
		isNegative = true
		num = -num
	}

	for num > 0 {
		sb.WriteRune(rune('0' + num%7))
		num = num / 7
	}

	str := sb.String()
	sb.Reset()
	if isNegative {
		sb.WriteRune('-')
	}
	for i := len(str) - 1; i >= 0; i-- {
		sb.WriteRune(rune(str[i]))
	}

	return sb.String()
}
