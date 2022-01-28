package leetcodetests

import "testing"

type testcase1996 struct {
	Data     [][]int
	Expected int
}

func TestIssue1996(t *testing.T) {
	testcases := []testcase1996{
		{Data: [][]int{{5, 5}, {6, 3}, {3, 6}}, Expected: 0},
		{Data: [][]int{{2, 2}, {3, 3}}, Expected: 1},
		{Data: [][]int{{1, 5}, {10, 4}, {4, 3}}, Expected: 1},
	}

	for i, tc := range testcases {
		actual := numberOfWeakCharacters(tc.Data)
		if actual != tc.Expected {
			t.Errorf("#%d: expected: %d, actual: %d.\n", i, tc.Expected, actual)
		}
	}
}
