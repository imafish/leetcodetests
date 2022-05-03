package leetcodetests

import "testing"

func TestIssue42(t *testing.T) {
	input := []int{4, 2, 0, 3, 2, 5}
	expected := 9
	actual := trap(input)

	if expected != actual {
		t.Errorf("Failed: expected: %d, actual: %d.", expected, actual)
	}
}
