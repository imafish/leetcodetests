package leetcodetests

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	numbers := make([]int, 0, 10)
	len := 0

	for x > 0 {
		numbers = append(numbers, x%10)
		x = x / 10
		len++
	}

	len--
	for i := 0; i < len; {
		if numbers[i] != numbers[len] {
			return false
		}
		i++
		len--
	}

	return true
}
