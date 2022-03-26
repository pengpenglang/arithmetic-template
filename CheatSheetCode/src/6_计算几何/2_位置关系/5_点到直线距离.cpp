point pointtoline(point P, line L) {
	point res;
	double t = ((P - L.s) * (L.e-L.s)) / ((L.e-L.s) * (L.e-L.s)); 
	res.x = L.s.x + (L.e.x - L.s.x) * t;
	res.y = L.s.y + (L.e.y - L.s.y) * t;
	return dist(P, res);
}
