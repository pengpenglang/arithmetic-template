const int maxn = 50010;
int sum[maxn << 2];
void PushUp(int rt) {
	sum[rt] = sum[lson] + sum[rson];
}
void build(int l, int r, int rt) {
	if (l == r) {scanf("%d", &sum[rt]); return;}	// 建立的时候直接输入叶节点
	int m = (l + r) >> 1;
	build(Lson); build(Rson);
	PushUp(rt);
}
void update(int p, int add, int l, int r, int rt) {
	if (l == r) {sum[rt] += add; return;}
	int m = (l + r) >> 1;
	if (p <= m) update(p, add, Lson);
	else update(p, add, Rson);
	PushUp(rt);
}
int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {return sum[rt];}
	int m = (l + r) >> 1, s = 0;
	if (L <= m) s += query(L, R, Lson);
	if (m < R) s += query(L, R, Rson);
	return s;
}
