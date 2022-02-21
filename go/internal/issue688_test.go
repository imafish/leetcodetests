package leetcodetests

import "testing"

type Testcase688 struct {
	N        int
	K        int
	Row      int
	Col      int
	Expected float64
}

func TestIssue688(t *testing.T) {
	testcases := []Testcase688{
		{
			N:        3,
			K:        2,
			Row:      0,
			Col:      0,
			Expected: 0.0625,
		},
		{
			N:        1,
			K:        0,
			Row:      0,
			Col:      0,
			Expected: 1.0,
		},
	}

	for i, tc := range testcases {
		actual := knightProbability(tc.N, tc.K, tc.Row, tc.Col)
		if actual != tc.Expected {
			t.Errorf("testcase #%d failed: expected: %f, actual: %f", i, tc.Expected, actual)
		}
	}
}
