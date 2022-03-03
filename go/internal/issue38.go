package leetcodetests

import (
	"strconv"
	"strings"
)

func countAndSay(n int) string {
	result := "1"

	for i := 1; i < n; i++ {
		result = sayOne(result)
	}
	return result
}

func sayOne(s string) string {
	var sb strings.Builder
	var last rune
	cnt := 0
	for _, c := range s {
		if c != last {
			if cnt > 0 {
				sb.WriteString(strconv.Itoa(cnt*10 + int(last-'0')))
			}
			cnt = 1
			last = c
		} else {
			cnt++
		}
	}
	if cnt > 0 {
		sb.WriteString(strconv.Itoa(cnt*10 + int(last-'0')))
	}

	return sb.String()
}
