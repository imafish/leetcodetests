package leetcodetests

type stack interface {
	PopHead()
	PushHead(value int)
	Head() int
	IsEmpty() bool
}

type sliceStack []int

type CQueue struct {
	s1 stack
	s2 stack
}

func (s *sliceStack) PopHead() {
	if len(*s) >= 0 {
		*s = (*s)[0 : len(*s)-1]
	}
}

func (s *sliceStack) PushHead(value int) {
	*s = append(*s, value)
}

func (s *sliceStack) Head() int {
	if len(*s) == 0 {
		return -1
	}
	return (*s)[len(*s)-1]
}

func (s *sliceStack) IsEmpty() bool {
	return len(*s) == 0
}

func Constructor2216() CQueue {
	s1 := sliceStack(make([]int, 0))
	s2 := sliceStack(make([]int, 0))
	return CQueue{
		s1: &s1,
		s2: &s2,
	}
}

func (queue *CQueue) AppendTail(value int) {
	queue.s1.PushHead(value)
}

func (queue *CQueue) DeleteHead() int {
	if !queue.s2.IsEmpty() {
		value := queue.s2.Head()
		queue.s2.PopHead()
		return value
	}

	for !queue.s1.IsEmpty() {
		value := queue.s1.Head()
		queue.s1.PopHead()
		queue.s2.PushHead(value)
	}

	if queue.s2.IsEmpty() {
		return -1
	}
	result := queue.s2.Head()
	queue.s2.PopHead()

	return result
}
