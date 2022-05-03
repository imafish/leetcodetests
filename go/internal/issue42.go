package leetcodetests

func trap(height []int) int {
	length := len(height)
	leftMax, rightMax := make([]int, length), make([]int, length)

	leftMax[0] = height[0]
	for i := 1; i < length; i++ {
		h := height[i]
		if leftMax[i-1] > h {
			leftMax[i] = leftMax[i-1]
		} else {
			leftMax[i] = h
		}

	}

	rightMax[length-1] = height[length-1]
	for i := length - 2; i >= 0; i-- {
		h := height[i]
		if rightMax[i+1] > h {
			rightMax[i] = rightMax[i+1]
		} else {
			rightMax[i] = h
		}
	}

	water := 0
	for i := 1; i < length-1; i++ {
		w := min(leftMax[i], rightMax[i]) - height[i]
		if w > 0 {
			water += w
		}
	}
	return water
}
