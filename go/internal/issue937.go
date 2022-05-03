package leetcodetests

import (
	"sort"
	"strings"
)

func reorderLogFiles(logs []string) []string {
	length := len(logs)
	letterLogs, numberLogs := make([]string, 0, length), make([]string, 0, length)
	for _, s := range logs {
		idx := strings.Index(s, " ")
		s1 := s[idx+1:]
		c := s1[0]
		if c >= 'a' && c <= 'z' {
			letterLogs = append(letterLogs, s)
		} else {
			numberLogs = append(numberLogs, s)
		}
	}

	sort.Slice(letterLogs, func(i int, j int) bool {
		idx1 := strings.Index(letterLogs[i], " ")
		idx2 := strings.Index(letterLogs[j], " ")
		s1 := letterLogs[i][idx1+1:]
		s2 := letterLogs[j][idx2+1:]
		if s1 == s2 {
			return letterLogs[i][:idx1] < letterLogs[j][:idx2]
		}
		return s1 < s2
	})
	return append(letterLogs, numberLogs...)
}
