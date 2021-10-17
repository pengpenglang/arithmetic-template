// 射线法,poly[]的顶点数要大于等于3,点的编号0~n-1
// -1 : 点在凸多边形外
// 0  : 点在凸多边形边界上
// 1  : 点在凸多边形内
int PointInPoly(point p, point poly[], int n) {
	int cnt;
	line ray, side;
	cnt = 0;
	ray.s = p;
	ray.e.y = p.y;
	ray.e.x = -100000000000.0; // -INF,注意取值防止越界
	for (int i = 0; i < n; i++) {
		side.s = poly[i];
		side.e = poly[(i + 1) % n];
		if (PointOnSeg(p, side))return 0;
		//如果平行轴则不考虑
		if (sgn(side.s.y - side.e.y) == 0)
			continue;
		if (PointOnSeg(sid e.s, r ay)) {
			if (sgn(side.s.y - side.e.y) > 0) cnt++;
		}
		else if (PointOnSeg(side.e, ray)) {
			if (sgn(side.e.y - side.s.y) > 0) cnt++;
		}
		else if (segxseg(ray, side)) cnt++;
	}
	return cnt % 2 == 1 ? 1 : -1;
}
