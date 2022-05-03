package leetcodetests

func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
	chan1, chan2 := make(chan int), make(chan int)

	go traverseSearchTree(root1, chan1)
	go traverseSearchTree(root2, chan2)

	v1, ok1 := <-chan1
	v2, ok2 := <-chan2

	result := make([]int, 0)

	for ok1 && ok2 {
		if v1 < v2 {
			result = append(result, v1)
			v1, ok1 = <-chan1
		} else {
			result = append(result, v2)
			v2, ok2 = <-chan2
		}
	}
	for ok1 {
		result = append(result, v1)
		v1, ok1 = <-chan1
	}
	for ok2 {
		result = append(result, v2)
		v2, ok2 = <-chan2
	}

	return result
}

func traverseSearchTree(root *TreeNode, value chan<- int) {
	defer close(value)

	if root == nil {
		return
	}

	current := root
	buffer1 := []*TreeNode{}

	for current != nil || len(buffer1) > 0 {
		for current != nil {
			buffer1 = append(buffer1, current)
			current = current.Left
		}

		length := len(buffer1)
		if length > 0 {
			current = buffer1[length-1]
			buffer1 = buffer1[:length-1]

			value <- current.Val
			current = current.Right
		}
	}
}
