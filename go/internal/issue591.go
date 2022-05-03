package leetcodetests

import "strings"

const (
	START              = iota
	TEXT               = iota
	LESS_THAN          = iota
	GREATER_THAN       = iota
	IN_TAG             = iota
	CDTEXT             = iota
	CDTEXT_CLOSING_TAG = iota
)

type tagstack []string

func (t *tagstack) Push(v string) {
	*t = append(*t, v)
}

func (t *tagstack) Pop() string {
	length := len(*t)
	if length == 0 {
		return ""
	}
	v := (*t)[length-1]
	*t = (*t)[:length-1]

	return v
}

func NewTagStack() tagstack {
	return make(tagstack, 0)
}

func isValid(code string) bool {
	// analyser status
	state := START
	stack := NewTagStack()
	tagNameBuffer := strings.Builder{}
	tagCount := 0
	startTag := true

	for i, c := range code {
		switch state {
		case START:
			if c != '<' {
				return false
			} else {
				state = IN_TAG
			}
		case CDTEXT:
			if c == ']' {
				tagNameBuffer.Reset()
				tagNameBuffer.WriteRune(c)
				state = CDTEXT_CLOSING_TAG
			}
		case CDTEXT_CLOSING_TAG:
			if tagNameBuffer.Len() == 2 && c == '>' {
				state = GREATER_THAN
			} else if tagNameBuffer.Len() == 1 && c == ']' {
				tagNameBuffer.WriteRune(c)
			} else {
				state = CDTEXT
			}
		case GREATER_THAN:
			state = TEXT
			fallthrough
		case TEXT:
			if c == '<' {
				state = LESS_THAN
			}
		case LESS_THAN:
			if c == '<' {
				return false
			} else if c == '>' {
				return false
			} else {
				tagNameBuffer.Reset()
				tagNameBuffer.WriteRune(c)
				state = IN_TAG
			}
		case IN_TAG:
			if c == '<' {
				return false
			} else if c == '>' {
				state = GREATER_THAN
				tagName := tagNameBuffer.String()
				if len(tagName) == 0 {
					return false
				}
				if tagName[0] == '/' {
					tagName = tagName[1:]
					openingTag := stack.Pop()
					if openingTag != tagName {
						return false
					}
					if len(stack) == 0 && i != len(code)-1 {
						return false
					}
					tagCount++
				} else {
					if validateTag(tagName) {
						stack.Push(tagName)
					} else {
						return false
					}
					startTag = false
				}
			} else {
				tagNameBuffer.WriteRune(c)
				if tagNameBuffer.Len() == 8 && tagNameBuffer.String() == "![CDATA[" {
					if startTag {
						return false
					} else {
						state = CDTEXT
					}
				}
			}
		}
	}

	return len(stack) == 0 && state == GREATER_THAN && tagCount > 0
}

func validateTag(tag string) bool {
	if len(tag) < 1 || len(tag) > 9 {
		return false
	}
	for _, r := range tag {
		if r < 'A' || r > 'Z' {
			return false
		}
	}
	return true
}
