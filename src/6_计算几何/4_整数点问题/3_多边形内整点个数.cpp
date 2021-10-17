int InSide(point p[], int n) {
	int i, area = 0;
	for (i = 0; i < n; i++) 
		area += p[(i + 1) % n].y * (p[i].x - p[(i + 2) % n].x);	
	return (fabs(area) - OnEdge(n, p)) / 2 + 1;
}
