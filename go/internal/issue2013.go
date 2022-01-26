package leetcodetests

type Point struct {
	X int
	Y int
}

type DetectSquares struct {
	//	indexWithX map[int]map[int]int
	indexWithY map[int]map[int]int
	data       map[Point]int
}

func Constructor() DetectSquares {
	return DetectSquares{
		//		indexWithX: make(map[int]map[int]int),
		indexWithY: make(map[int]map[int]int),
		data:       make(map[Point]int),
	}
}

func (ds *DetectSquares) Add(point []int) {
	p := Point{point[0], point[1]}

	hasRecord := false

	if record, ok := ds.data[p]; ok {
		ds.data[p] = record + 1
	} else {
		ds.data[p] = 1
	}
	/*
		if ys, ok := ds.indexWithX[p.X]; ok {
			if hasRecord {
				hasRecord = true
				ys[p.Y] = ys[p.Y] + 1
			} else {
				ys[p.Y] = 1
			}
		} else {
			ds.indexWithX[p.X] = map[int]int{p.Y: 1}
		}
	*/
	if xs, ok := ds.indexWithY[p.Y]; ok {
		if hasRecord {
			xs[p.X] = xs[p.X] + 1
		} else {
			xs[p.X] = 1
		}
	} else {
		ds.indexWithY[p.Y] = map[int]int{p.X: 1}
	}
}

func (ds *DetectSquares) Count(point []int) int {
	p := Point{point[0], point[1]}
	var p1, p2, p3 Point
	var p1Count, p2Count, p3Count int
	total := 0

	// look for point 1
	if xs, ok := ds.indexWithY[p.Y]; ok {
		for xi := range xs {
			if xi != p.X {
				// found point 1
				p1.X = xi
				p1.Y = p.Y
				p1Count = ds.data[p1]

				// look for p2 & p3
				width := p1.X - p.X
				for _, w := range []int{width, -width} {
					p2.X = xi
					p2.Y = p.Y + w
					p3.X = p.X
					p3.Y = p2.Y
					if p2Count, ok = ds.data[p2]; ok {
						if p3Count, ok = ds.data[p3]; ok {
							total = total + p1Count*p2Count*p3Count
						}
					}
				}
			}
		}
	}

	return total
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(point);
 * param_2 := obj.Count(point);
 */
