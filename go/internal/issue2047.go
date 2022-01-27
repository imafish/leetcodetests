package leetcodetests

func countValidWords(sentence string) int {
	strlen := len(sentence)
	if strlen == 0 {
		return 0
	}

	cnt := 0
	idx := 0
	ct_previous := CharType_INVALID
	ct := getCharType(sentence[idx])

	in_word := false
	word_valid := false
	alreadyFoundHythen := false

	for {
		var ct_next CharType
		if idx < strlen-1 {
			ct_next = getCharType(sentence[idx+1])
		} else {
			ct_next = CharType_INVALID
		}

		if !in_word && ct != CharType_SPACE {
			in_word = true
			word_valid = true
			alreadyFoundHythen = false
		}

		if in_word {
			switch ct {
			case CharType_SPACE:
				if word_valid {
					cnt++
				}
				in_word = false

			case CharType_HYPHEN:
				if alreadyFoundHythen {
					word_valid = false
				} else if ct_next != CharType_CHAR || ct_previous != CharType_CHAR {
					word_valid = false
				}
				alreadyFoundHythen = true

			case CharType_PUNCTURE:
				if ct_next != CharType_SPACE && idx != strlen-1 {
					word_valid = false
				}

			case CharType_NUMBER:
				word_valid = false
			}
		}

		if idx == strlen-1 {
			if in_word && word_valid {
				cnt++
			}
			break
		}

		idx++
		ct_previous = ct
		ct = ct_next
	}

	return cnt
}

type CharType int32

const (
	CharType_SPACE    CharType = iota
	CharType_CHAR     CharType = iota
	CharType_HYPHEN   CharType = iota
	CharType_PUNCTURE CharType = iota
	CharType_NUMBER   CharType = iota
	CharType_INVALID  CharType = iota
)

func getCharType(b byte) CharType {
	switch {
	case b == ' ':
		return CharType_SPACE
	case b >= 'a' && b <= 'z':
		return CharType_CHAR
	case b == '-':
		return CharType_HYPHEN
	case b == '.' || b == ',' || b == '!':
		return CharType_PUNCTURE
	case b >= '0' && b <= '9':
		return CharType_NUMBER
	default:
		return CharType_INVALID
	}
}
