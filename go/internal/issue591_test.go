package leetcodetests

import "testing"

func TestIssue591(t *testing.T) {
	s := "<DIV>This is the first line <![CDATA[<div>]]></DIV>"
	actual := isValid(s)
	if !actual {
		t.Errorf("expected to be true.")
	}
}
