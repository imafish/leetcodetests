package leetcodetests

import "testing"

type issue2216TestCase struct {
	operations []string
	data       []int
	expected   []int

	queue *CQueue
}

func TestIssue2216(t *testing.T) {
	testcases := []issue2216TestCase{
		{
			operations: []string{"CQueue", "appendTail", "deleteHead", "deleteHead"},
			data:       []int{0, 3, 0, 0},
			expected:   []int{0, 0, 3, -1},
		},
		{
			operations: []string{"CQueue", "deleteHead", "appendTail", "appendTail", "deleteHead", "deleteHead"},
			data:       []int{0, 0, 5, 2, 0, 0},
			expected:   []int{0, -1, 0, 0, 5, 2},
		},
	}

	for i, tc := range testcases {
		for j, op := range tc.operations {
			switch op {
			case "CQueue":
				obj := Constructor2216()
				tc.queue = &obj
			case "appendTail":
				tc.queue.AppendTail(tc.data[j])
			case "deleteHead":
				actual := tc.queue.DeleteHead()
				if actual != tc.expected[j] {
					t.Errorf("testcase #%d, operation #%d: expected: %d, actual %d", i, j, tc.expected[j], actual)
				}
			}
		}
	}
}
