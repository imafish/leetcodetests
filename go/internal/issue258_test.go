package leetcodetests

import "testing"

func TestIssue258(t *testing.T) {
	cases := []int{
		0,
		1,
		11,
		123,
		736346365,
		999999999,
		2,
	}
	expected := []int{
		0,
		1,
		2,
		6,
		7,
		9,
		2,
	}

	for i, c := range cases {
		actual := addDigits(c)
		if actual != expected[i] {
			t.Errorf("#%d (addDigits(%d)): expected: %d, actual: %d.", i, c, expected[i], actual)
		}
	}
}
