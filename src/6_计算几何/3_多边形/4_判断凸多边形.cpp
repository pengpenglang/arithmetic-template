// 点可以是顺时针给出也可以是逆时针给出
// 点的编号1~n-1
bool isconvex(point poly[], int n) {
	bool s[3];
	set(s, 0);
	for (int i = 0; i < n; i++) {
		s[sgn((poly[(i + 1) % n] - poly[i]) ^ (poly[(i + 2) % n] - poly[i]) ) + 1] = 1;
		if (s[0] && s[2]) return 0;
	}
	return 1;
}
