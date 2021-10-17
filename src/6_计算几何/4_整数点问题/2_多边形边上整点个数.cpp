int OnEdge(point p[], int n) {
	int i, ret = 0;
	for (i = 0; i < n; i++)
		ret += __gcd(fabs(p[i].x - p[(i + 1) % n].x), fabs(p[i].y - p[(i + 1) % n].y));
	return ret;
}
