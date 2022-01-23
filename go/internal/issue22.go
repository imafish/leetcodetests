/*
22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：
```
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
```

示例 2：
```
输入：n = 1
输出：["()"]
```

提示：
```
1 <= n <= 8
```
*/

package main

import "strings"

func generateParenthesis(n int) []string {
	if n == 1 {
		return []string{"()"}
	}

	results := make([][]string, n+1)
	results[0] = []string{""}
	results[1] = []string{"()"}

	for i := 2; i <= n; i++ {
		result := make([]string, 0, len(results[i-1]))

		for j := 0; j < i; j++ {
			k := i - j - 1

			for _, v1 := range results[j] {
				for _, v2 := range results[k] {
					pair := strings.Join([]string{"(", v1, ")", v2}, "")
					result = append(result, pair)
				}
			}
		}
		results[i] = result
	}

	return results[n]
}
