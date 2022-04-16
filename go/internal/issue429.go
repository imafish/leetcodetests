package leetcodetests

type Node struct {
	Val      int
	Children []*Node
}

func levelOrder(root *Node) [][]int {
	result := make([][]int, 0)

	if root == nil {
		return result
	}

	processing := []*Node{root}
	next := make([]*Node, 0)

	for len(processing) > 0 {
		thisLayer := make([]int, 0)
		for _, n := range processing {
			next = append(next, n.Children...)
			thisLayer = append(thisLayer, n.Val)
		}
		result = append(result, thisLayer)
		processing, next = next, processing
		next = next[0:0]
	}

	return result
}
