package leetcodetests

import "testing"

type testcase2044 struct {
	Nums     []int
	Expected int
}

func TestIssue2044(t *testing.T) {
	cases := []testcase2044{
		{[]int{3, 1}, 2},
		{[]int{2, 2, 2}, 7},
		{[]int{3, 2, 1, 5}, 6},
	}

	for i, c := range cases {
		actual := countMaxOrSubsets(c.Nums)
		if actual != c.Expected {
			t.Errorf("#%d (%v): expected: %d, actual %d", i, c.Nums, c.Expected, actual)
		}
	}
}
