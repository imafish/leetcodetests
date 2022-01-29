package leetcodetests

import "testing"

type testcase1765 struct {
	Data     [][]int
	Expected int
}

func TestIssue1765(t *testing.T) {
	testcases := []testcase1765{
		{
			Data:     [][]int{{0, 1}, {0, 0}},
			Expected: 2,
		},
		{
			Data:     [][]int{{1, 1, 0, 1, 1, 1}, {1, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 0}, {1, 1, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 1}, {1, 1, 0, 1, 0, 1}},
			Expected: 1,
		},
		{
			Data:     [][]int{{0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0}},
			Expected: 5,
		},
	}

	for i, tc := range testcases {
		result := highestPeak(tc.Data)
		analysis(t, i, tc, result)
	}
}

func analysis(t *testing.T, index int, tc testcase1765, result [][]int) {
	iSize, jSize := len(tc.Data), len(tc.Data[0])
	max := 0
	invalidBlocks := make([][2]int, 0)
	directions := [][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}

	for i := 0; i < iSize; i++ {
		for j := 0; j < jSize; j++ {
			value := result[i][j]
			if value > max {
				max = value
			}
			for _, d := range directions {
				ii, jj := i+d[0], j+d[1]
				if ii >= 0 && ii < iSize-1 && jj >= 0 && jj < jSize-1 {
					otherValue := result[ii][jj]
					if value > otherValue+1 || value < otherValue-1 {
						invalidBlocks = append(invalidBlocks, [2]int{i, j})
						break
					}
				}
			}
		}
	}

	if len(invalidBlocks) > 0 || max != tc.Expected {
		t.Errorf("Found error in testcase #%d, printing input and output.\n", index)

		t.Log("-------INPUT -------\n")
		printData(t, tc.Data)
		t.Log("-------RESULT-------\n")
		printData(t, result)

		if max != tc.Expected {
			t.Logf("expected: %d, actual %d.\n", tc.Expected, max)
		}
		if len(invalidBlocks) > 0 {
			t.Logf("%d invalid blocks: \n", len(invalidBlocks))
			for i, ib := range invalidBlocks {
				t.Logf("  invalid block %d: {%d, %d}\n", i, ib[0], ib[1])
			}
		}

	}

}

func printData(t *testing.T, data [][]int) {
	for _, row := range data {
		for _, v := range row {
			t.Logf("%d ", v)
		}
		t.Logf("\n")
	}
}
