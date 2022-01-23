package leetcodetests

import (
	"testing"
)

func TestLengthOfLongestSubstring(t *testing.T) {
	data := map[string]int{
		"":              0,
		"a":             1,
		"abc":           3,
		"aa":            1,
		"abcda":         4,
		"abcdabcdefg":   7,
		"abcdefdeghijk": 8,
	}

	for k, v := range data {
		result := lengthOfLongestSubstring(k)

		if result != v {
			t.Errorf("'%s': expected: %d, actual: %d.\n", k, v, result)
		}
	}
}

func TestLengthOfLongestSubstringWithIssue(t *testing.T) {
	result := lengthOfLongestSubstring("tmmzuxt")

	if result != 5 {
		t.Errorf("Expected 5, got %d", result)
	}
}
