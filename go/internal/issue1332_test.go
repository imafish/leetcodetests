package leetcodetests

import "testing"

func TestIssue1332(t *testing.T) {
	data := map[string]int{
		"":       0,
		"a":      1,
		"aaaab":  2,
		"ababa":  1,
		"ababab": 2,
		"aaaaa":  1,
	}

	for k, v := range data {
		actual := removePalindromeSub(k)
		if actual != v {
			t.Errorf("`%s`: expected: %d, actual: %d.\n", k, v, actual)
		}
	}
}
