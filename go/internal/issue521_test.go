package leetcodetests

import "testing"

func TestIssue521(t *testing.T) {
	cases := [][2]string{
		{"aba", "cdc"},
		{"aaa", "bbb"},
		{"aaa", "aaa"},
	}
	expected := []int{
		3,
		3,
		-1,
	}

	for i, c := range cases {
		actual := findLUSlength(c[0], c[1])
		if actual != expected[i] {
			t.Errorf("#%d (%v): expected: %d, actual: %d.", i, c, expected[i], actual)
		}
	}
}
