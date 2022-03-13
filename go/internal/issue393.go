package leetcodetests

func validUtf8(data []int) bool {
	state := 0
	for _, i := range data {
		if state == 0 {
			switch {
			case (i & 0xF8) == 0xF0:
				state = 3
			case (i & 0xF0) == 0xE0:
				state = 2
			case (i & 0xE0) == 0xC0:
				state = 1
			case (i & 0x80) == 0:
				state = 0
			default:
				return false
			}
		} else if (i & 0xC0) == 0x80 {
			state--
		} else {
			return false
		}
	}
	return state == 0
}
