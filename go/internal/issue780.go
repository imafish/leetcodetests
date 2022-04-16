package leetcodetests

func reachingPoints(sx int, sy int, tx int, ty int) bool {
	for tx > sx && ty > sy && tx != ty {
		if tx > ty {
			tx = tx % ty
		} else {
			ty = ty % tx
		}
	}
	if tx < sx || ty < sy {
		return false
	} else if tx == sx && (ty-sy)%sx == 0 {
		return true
	} else if ty == sy && (tx-sx)%sy == 0 {
		return true
	} else {
		return false
	}
}
