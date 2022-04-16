package leetcodetests

import (
	"strings"
)

func mostCommonWord(paragraph string, banned []string) string {
	bannedMap := make(map[string]bool)
	wordMap := make(map[string]int)
	maxWord, maxCount := "", 0

	for _, w := range banned {
		bannedMap[w] = true
	}

	sb := strings.Builder{}
	for _, r := range paragraph {
		if r >= 'a' && r <= 'z' {
			sb.WriteRune(r)
		} else if r >= 'A' && r <= 'Z' {
			sb.WriteRune(r + 'a' - 'A')
		} else if sb.Len() > 0 {
			word := sb.String()
			sb.Reset()
			if _, ok := bannedMap[word]; ok {
				continue
			}
			wordMap[word]++
			cnt := wordMap[word]
			if cnt > maxCount {
				maxCount = cnt
				maxWord = word
			}
		}
	}
	if sb.Len() > 0 {
		word := sb.String()
		if _, ok := bannedMap[word]; !ok {
			wordMap[word]++
			cnt := wordMap[word]
			if cnt > maxCount {
				maxCount = cnt
				maxWord = word
			}
		}
	}

	return maxWord
}
