package leetcodetests

import "testing"

func TestIssue9(t *testing.T) {
	data := map[int]bool{
		1:           true,
		-1:          false,
		0:           true,
		123454321:   true,
		1234554321:  true,
		123123:      false,
		-1234554321: false,
		-123454321:  false,
	}

	for k, expected := range data {
		actual := isPalindrome(k)
		if actual != expected {
			t.Errorf("`%d`: expected: %t, actual %t.\n", k, expected, actual)
		}
	}
}
