point pointtosegment(point p, line l) {
	point res;
	double t = ((p - l.s) * (l.e-l.s)) / ((l.e-l.s) * (l.e-l.s));
	if (t >= 0 && t <= 1) {
		res.x = l.s.x + (l.e.x - l.s.x) * t;
		res.y = l.s.y + (l.e.y - l.s.y) * t;
	}
	else res = dist(p, l.s) < dist(p, l.e) ? l.s : l.e;
	return res;
}
