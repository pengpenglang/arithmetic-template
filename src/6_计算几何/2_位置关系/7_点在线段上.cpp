bool PointOnSeg(point p, line l) {
	return
	    sgn((l.s - p) ^ (l.e-p)) == 0 &&
	    sgn((p.x - l.s.x) * (p.x - l.e.x)) <= 0 &&
	    sgn((p.y - l.s.y) * (p.y - l.e.y)) <= 0;
}
