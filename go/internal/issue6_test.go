package leetcodetests

import "testing"

func TestConvert(t *testing.T) {
	result := convert("PAYPALISHIRING", 3)
	if result != "PAHNAPLSIIGYIR" {
		t.Errorf("expected: PAHNAPLSIIGYIR, got: '%s'.\n", result)
	}
	//convert("PAHNAPLSIIGYIR", 4)
}
