package leetcodetests

import "strings"

func multiply(num1 string, num2 string) string {
	len1, len2 := len(num1), len(num2)
	b1, b2 := make([]byte, len1), make([]byte, len2)
	for i := len1 - 1; i >= 0; i-- {
		b1[len1-i-1] = num1[i] - '0'
	}
	for i := len2 - 1; i >= 0; i-- {
		b2[len2-i-1] = num2[i] - '0'
	}

	result := make([]byte, len1+len2+1)

	for i, n := range b2 {
		stringAdd(result, b1, n, i)
	}

	end := len(result) - 1
	for end >= 0 {
		if result[end] != 0 {
			break
		}
		end--
	}
	sb := strings.Builder{}
	for end >= 0 {
		sb.WriteByte(result[end] + '0')
		end--
	}

	if sb.Len() == 0 {
		sb.WriteByte('0')
	}
	return sb.String()
}

func stringAdd(result []byte, num1 []byte, b byte, bits int) {
	var add byte

	num2 := make([]byte, len(num1)+1)
	for i, n := range num1 {
		num2[i] = b*n + add
		add = num2[i] / 10
		num2[i] = num2[i] % 10
	}
	if add > 0 {
		num2[len(num1)] += add
	}

	add = 0
	for i, b2 := range num2 {
		j := i + bits
		result[j] += b2 + add
		add = result[j] / 10
		result[j] = result[j] % 10
	}
	if add == 1 {
		result[len(num2)] += 1
	}
}
