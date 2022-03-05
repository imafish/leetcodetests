package leetcodetests

import (
	"sort"
	"testing"
)

func TestIssue39(t *testing.T) {
	candidates := [][]int{
		{2, 3, 6, 7},
		{2, 3, 5},
		{2},
	}
	targets := []int{
		7,
		8,
		1,
	}
	expected := [][][]int{
		{{2, 2, 3}, {7}},
		{{2, 2, 2, 2}, {2, 3, 3}, {3, 5}},
		{},
	}

	for i, c := range candidates {
		actual := combinationSum(c, targets[i])
		if !intSliceSortEqual(actual, expected[i]) {
			t.Errorf("#%d (%v): expected: %v, actual: %v.", i, c, expected[i], actual)
		}
	}
}

func intSliceSortEqual(a, b [][]int) bool {
	if len(a) != len(b) {
		return false
	}

	lessFunc := func(arr [][]int, i, j int) bool {
		ai, aj := arr[i], arr[j]
		reverse := false
		if len(ai) > len(aj) {
			ai, aj = aj, ai
			reverse = true
		}

		for k, vi := range ai {
			if vi < aj[k] {
				if reverse {
					return false
				} else {
					return true
				}
			} else if vi > aj[k] {
				if reverse {
					return true
				} else {
					return false
				}
			}
		}
		if reverse {
			return false
		} else {
			return true
		}
	}
	sort.Slice(a, func(i, j int) bool { return lessFunc(a, i, j) })
	sort.Slice(b, func(i, j int) bool { return lessFunc(b, i, j) })

	for i, av := range a {
		bv := b[i]

		if len(av) != len(bv) {
			return false
		}

		for j, avv := range av {
			if avv != bv[j] {
				return false
			}
		}
	}
	return true
}
