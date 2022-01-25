package leetcodetests

import (
	"math"
	"testing"
)

func TestIssue7(t *testing.T) {
	data := map[int]int{
		-(2 ^ 31):     0,
		0:             0,
		1:             1,
		123:           321,
		-123:          -321,
		math.MaxInt32: 0,
		1534236469:    0,
	}

	for k, v := range data {
		result := reverse(k)
		if result != v {
			t.Errorf("number %d: expected (%d), actual (%d).\n", k, v, result)
		}
	}
}
