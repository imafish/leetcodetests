package leetcodetests

type NumArray struct {
	values []int
	tree   []int
}

func (na *NumArray) preSum(i int) int {
	i++
	sum := 0
	for i > 0 {
		sum += na.tree[i]
		lowbit := i & (-i)
		i -= lowbit
	}
	return sum
}

func (na *NumArray) add(i int, v int) {
	delta := v - na.values[i]
	i++
	for ; i < len(na.tree); i += (i & (-i)) {
		na.tree[i] += delta
	}
}

func Constructor(nums []int) NumArray {
	result := NumArray{nums, make([]int, len(nums)+1)}
	for i, v := range nums {
		result.add(i, v)
	}
	return result
}

func (this *NumArray) Update(index int, val int) {
	this.add(index, val)
	this.values[index] = val
}

func (this *NumArray) SumRange(left int, right int) int {
	if left == 0 {
		return this.preSum(right)
	} else {
		return this.preSum(right) - this.preSum(left-1)
	}
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * obj.Update(index,val);
 * param_2 := obj.SumRange(left,right);
 */
