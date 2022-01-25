package leetcodetests

import (
	"testing"
)

func TestIssue22(t *testing.T) {
	data := map[int][]string{
		3: {"((()))", "(()())", "(())()", "()(())", "()()()"},
	}

	for k, v := range data {
		actual := generateParenthesis(k)

		if len(actual) == len(v) {
			map1 := make(map[string]bool)
			for _, x := range actual {
				map1[x] = true
			}
			for _, x := range v {
				if _, ok := map1[x]; !ok {
					t.Errorf("%d: expected: %v, got: %v.\n", k, v, actual)
					break
				}
			}
		}

	}
}
