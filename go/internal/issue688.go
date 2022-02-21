package leetcodetests

func knightProbability(n int, k int, row int, column int) float64 {
	if k == 0 {
		if row >= 0 && row < n && column >= 0 && column < n {
			return 1.0
		} else {
			return 0.0
		}
	}

	dp := make([][][]float64, k)
	for i := range dp {
		dp[i] = make([][]float64, n)
		for j := range dp[i] {
			dp[i][j] = make([]float64, n)
			for k := range dp[i][j] {
				dp[i][j][k] = 1.0
			}
		}
	}

	directions := [8][2]int{
		{1, 2},
		{2, 1},
		{1, -2},
		{2, -1},
		{-1, -2},
		{-2, -1},
		{-1, 2},
		{-2, 1},
	}

	for i := 1; i < k; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				p := 0.0
				for l := 0; l < 8; l++ {
					nx, ny := j+directions[l][0], k+directions[l][1]
					if nx >= 0 && nx < n && ny >= 0 && ny < n {
						p += 0.125 * dp[i-1][nx][ny]
					}
				}
				dp[i][j][k] = p
			}
		}
	}

	p := 0.0
	for l := 0; l < 8; l++ {
		nx, ny := row+directions[l][0], column+directions[l][1]
		if nx >= 0 && nx < n && ny >= 0 && ny < n {
			p += 0.125 * dp[k-1][nx][ny]
		}
	}
	return p
}
