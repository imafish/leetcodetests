package leetcodetests

import "math/rand"

type RandomizedSet struct {
	set map[int]int
	arr []int
}

func ConstructorIssue380() RandomizedSet {
	return RandomizedSet{make(map[int]int), make([]int, 0)}
}

func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.set[val]; ok {
		return false
	}
	this.set[val] = len(this.arr)
	this.arr = append(this.arr, val)
	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	if i, ok := this.set[val]; ok {
		delete(this.set, val)
		last := this.arr[len(this.arr)-1]
		this.arr[i] = last
		this.set[last] = i
		this.arr = this.arr[0 : len(this.arr)-1]
		return true
	} else {
		return false
	}
}

func (this *RandomizedSet) GetRandom() int {
	random := rand.Intn(len(this.arr))
	return this.arr[random]
}
