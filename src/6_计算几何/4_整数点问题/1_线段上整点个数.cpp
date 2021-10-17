int OnSegment(line l) {
	return __gcd(fabs(l.s.x - l.e.x), fabs(l.s.y - l.e.y)) + 1;
}
