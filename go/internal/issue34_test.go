package leetcodetests

import "testing"

type Testcase34 struct {
	Nums     []int
	Target   int
	Expected []int
}

func TestIssue34(t *testing.T) {
	testcases := []Testcase34{
		{
			Nums:     []int{1},
			Target:   1,
			Expected: []int{0, 0},
		},
		{
			Nums:     []int{5, 7, 7, 8, 8, 10},
			Target:   8,
			Expected: []int{3, 4},
		},
	}

	for i, tc := range testcases {
		result := searchRange(tc.Nums, tc.Target)
		if result[0] != tc.Expected[0] || result[1] != tc.Expected[1] {
			t.Errorf("testcase %d failed: Expected: %v, Actual: %v", i, tc.Expected, result)
		}
	}
}
