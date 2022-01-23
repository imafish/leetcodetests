package main

import "testing"

func TestIssue5(t *testing.T) {
	data := map[string][]string{
		"":      {""},
		"a":     {"a"},
		"aa":    {"aa"},
		"ac":    {"a", "c"},
		"cbbd":  {"bb"},
		"babad": {"bab", "aba"},
	}

	for k, v := range data {
		actual := longestPalindrome(k)

		matched := false
		for _, expected := range v {
			if expected == actual {
				matched = true
			}
		}
		if !matched {
			t.Errorf("'%s': expected: '%v', got: '%s'.\n", k, v, actual)
		}
	}
}

func TestIssue5EdgeCase(t *testing.T) {
	e := longestPalindrome("aa")
	if e != "aa" {
		t.Errorf("GOT: '%s'.\n", e)
	}
}
