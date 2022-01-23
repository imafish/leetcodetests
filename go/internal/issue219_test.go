package main

import "testing"

type issue219 struct {
	Nums     []int
	K        int
	Expected bool
}

func TestIssue219(t *testing.T) {
	data := []issue219{
		{[]int{1, 2, 3, 1}, 3, true},
		{[]int{1, 0, 1, 1}, 1, true},
		{[]int{1, 2, 3, 1, 2, 3}, 2, false},
		{[]int{1, 2, 3, 1, 1, 2, 3}, 0, false},
	}

	for _, v := range data {
		actual := containsNearbyDuplicate(v.Nums, v.K)
		if actual != v.Expected {
			t.Errorf("%v + %d: expected: %t, actual %t.\n", v.Nums, v.K, v.Expected, actual)
		}
	}
}
