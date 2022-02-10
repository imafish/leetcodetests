package leetcodetests

import (
	"sort"
	"testing"
)

func TestIssue18(t *testing.T) {
	arr := [][]int{
		{1, 0, -1, 0, -2, 2},
	}
	targets := []int{
		0,
	}
	expected := [][][]int{
		{
			{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1},
		},
	}

	for i, nums := range arr {
		target := targets[i]
		actual := fourSum(nums, target)
		e := expected[i]

		if !compareResult18(e, actual) {
			t.Errorf("case #%d failed: expected: %v, actual: %v", i, e, actual)
		}
	}
}

func compareResult18(expected [][]int, actual [][]int) bool {
	if len(expected) != len(actual) {
		return false
	}

	for i, e := range expected {
		a := actual[i]
		sort.Slice(e, func(x int, y int) bool { return e[x] < e[y] })
		sort.Slice(a, func(x int, y int) bool { return a[x] < a[y] })
	}
	sort.Slice(expected, func(x int, y int) bool {
		return compareSliceIssue18(expected[x], expected[y])
	})
	sort.Slice(actual, func(x int, y int) bool {
		return compareSliceIssue18(actual[x], actual[y])
	})

	for i, e := range expected {
		if !sliceEqualIssue18(e, actual[i]) {
			return false
		}
	}
	return true
}

func sliceEqualIssue18(e []int, i []int) bool {
	for a, b := range e {
		if b != i[a] {
			return false
		}
	}
	return true
}

func compareSliceIssue18(s1 []int, s2 []int) bool {
	if s1[0] < s2[0] {
		return true
	} else if s1[0] > s2[0] {
		return false
	} else if len(s1) == 1 {
		return false
	} else {
		return compareSliceIssue18(s1[1:], s2[1:])
	}
}
