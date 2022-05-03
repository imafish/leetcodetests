package leetcodetests

func postorder(root *Node) []int {
	result := make([]int, 0)

	history := make(map[*Node]bool)
	stack := make([]*Node, 0)
	if root != nil {
		stack = append(stack, root)
	}

	for len(stack) > 0 {
		current := stack[len(stack)-1]
		if len(current.Children) == 0 {
			result = append(result, current.Val)
			stack = stack[0 : len(stack)-1]
		} else if _, ok := history[current]; ok {
			delete(history, current)
			result = append(result, current.Val)
			stack = stack[0 : len(stack)-1]
		} else {
			history[current] = true
			for i := len(current.Children) - 1; i >= 0; i-- {
				stack = append(stack, current.Children[i])
			}
		}
	}
	return result
}
