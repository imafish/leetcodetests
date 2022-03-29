package leetcodetests

func trap(height []int) int {
	water := 0
	h := 0
	length := len(height)
	max := 0
	for {
		w := 0
		start := false
		starti := 0
		for i := 0; i < length; i++ {
			if h == 0 && height[i] > max {
				max = height[i]
			}
			if height[i] > h {
				if start {
					w += i - starti - 1
					starti = i
				} else {
					start = true
					starti = i
				}
			}
		}
		water += w
		if h >= max {
			return water
		}
		h++
	}
}
