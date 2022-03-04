package leetcodetests

import "testing"

func TestIssue2104(t *testing.T) {
	cases := [][]int{
		{1, 2, 3},
		{1, 3, 3},
		{4, -2, -3, 4, 1},
	}
	expected := []int64{
		4,
		4,
		59,
	}

	for i, c := range cases {
		actual := subArrayRanges(c)
		if actual != expected[i] {
			t.Errorf("#%d (%v): expected %d, got %d", i, c, expected[i], actual)
		}
	}
}
