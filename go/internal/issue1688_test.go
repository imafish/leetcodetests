package leetcodetests

import "testing"

func TestIssue1688(t *testing.T) {
	data := map[int]int{
		1: 0,
		2: 1,
		3: 2,
		4: 3,
		5: 4,
		6: 5,
	}

	for k, expected := range data {
		actual := numberOfMatches(k)
		if actual != expected {
			t.Errorf("`%d`: expected: %d, got %d.\n", k, expected, actual)
		}
	}
}
