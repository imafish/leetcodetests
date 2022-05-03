package leetcodetests

import "math"

func divide(dividend int, divisor int) int {
	if divisor == 0 {
		return 0
	} else if dividend == math.MinInt32 {
		if divisor == 1 {
			return math.MinInt32
		} else if divisor == -1 {
			return math.MaxInt32
		}
	} else if divisor == math.MinInt32 {
		if dividend == math.MinInt32 {
			return 1
		} else {
			return 0
		}
	}

	reversed := false
	if dividend > 0 {
		dividend = -dividend
		reversed = !reversed
	}
	if divisor > 0 {
		divisor = -divisor
		reversed = !reversed
	}

	l, r := 1, math.MaxInt32
	result := 0
	for l <= r {
		mid := l + ((r - l) >> 1)
		check := quickAdd(divisor, mid, dividend)
		if check {
			result = mid
			if mid == math.MaxInt32 {
				break
			}
			l = mid + 1
		} else {
			r = mid - 1
		}
	}

	if reversed {
		return -result
	}
	return result
}

func quickAdd(y int, z int, x int) bool {

	// x 和 y 是负数，z 是正数
	// 需要判断 z * y >= x 是否成立
	result, add := 0, y
	for z != 0 {
		if z&1 == 1 {
			// 需要保证 result + add >= x
			if result < x-add {
				return false
			}
			result += add
		}
		if z != 1 {
			// 需要保证 add + add >= x
			if add < x-add {
				return false
			}
			add += add
		}
		// 不能使用除法
		z >>= 1
	}
	return true
}
