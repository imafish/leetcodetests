package leetcodetests

import "math/bits"

func countPrimeSetBits(left int, right int) int {
	mask := 0
	for _, p := range []int{2, 3, 5, 7, 11, 13, 17, 19} {
		mask += 1 << p
	}

	n := 0
	lu, ru := uint(left), uint(right)
	for ; lu <= ru; lu++ {
		if ((1 << bits.OnesCount(lu)) & mask) > 0 {
			n++
		}
	}
	return n
}
