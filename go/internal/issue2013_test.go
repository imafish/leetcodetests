package leetcodetests

import "testing"

type TestCase2013 struct {
	Action   []string
	Data     [][]int
	Expected []int
}

func TestIssue2013(t *testing.T) {
	testcases := []TestCase2013{
		{
			Action:   []string{"add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count", "add", "add", "add", "count"},
			Data:     [][]int{{5, 10}, {10, 5}, {10, 10}, {5, 5}, {3, 0}, {8, 0}, {8, 5}, {3, 5}, {9, 0}, {9, 8}, {1, 8}, {1, 0}, {0, 0}, {8, 0}, {8, 8}, {0, 8}},
			Expected: []int{-1, -1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 2},
		},
		{
			Action:   []string{"add", "add", "add", "count", "count", "add", "count"},
			Data:     [][]int{{3, 10}, {11, 2}, {3, 2}, {11, 10}, {14, 8}, {11, 2}, {11, 10}},
			Expected: []int{0, 0, 0, 1, 0, 0, 2},
		},
	}

	for ti, testcase := range testcases {

		detectSquares := ConstructorIssue2013()
		ds := &detectSquares

		for i, a := range testcase.Action {
			d := testcase.Data[i]
			e := testcase.Expected[i]

			switch a {
			case "add":
				ds.Add(d)
			case "count":
				actual := ds.Count(d)
				if actual != e {
					t.Errorf("testcase #%d, action #%d: expected: %d, actual %d.\n", ti, i, e, actual)
				}
			}
		}
	}
}
