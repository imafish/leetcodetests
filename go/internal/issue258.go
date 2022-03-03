package leetcodetests

func addDigits(num int) int {
	for num > 9 {
		n := 0
		for num > 0 {
			n += num % 10
			num /= 10
		}
		num = n
	}
	return num
}
