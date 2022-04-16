package leetcodetests

import "testing"

func TestIssue380(t *testing.T) {
	rs := RandomizedSet{make[int]int, make([]int,0)}
	rs.Insert(0)
	rs.Insert(1)
	rs.Remove(0)
	rs.Insert(2)
	rs.Remove(1)
	actual:=rs.GetRandom()
	if actual != 2 {
		t.Errorf("expected: 2, actual: %d\n", actual)
	}
}
