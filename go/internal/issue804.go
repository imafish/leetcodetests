package leetcodetests

import "strings"

var morseMap = []string{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}

func uniqueMorseRepresentations(words []string) int {
	translations := make(map[string]struct{})
	var sb strings.Builder
	for _, w := range words {
		for _, r := range w {
			sb.WriteString(morseMap[r-'a'])
		}
		translations[sb.String()] = struct{}{}
		sb.Reset()
	}

	return len(translations)
}
