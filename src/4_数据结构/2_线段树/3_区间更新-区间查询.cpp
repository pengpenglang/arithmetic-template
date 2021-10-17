// seg[rt]用于存放懒惰标记，注意PushDown时标记的传递
const int maxn = 101010;
int seg[maxn << 2], sum[maxn << 2];
void PushUp(int rt) {
	sum[rt] = sum[lson] + sum[rson];
}
void PushDown(int rt, int m) {
	if (seg[rt] == 0) return;
	seg[lson] += seg[rt];
	seg[rson] += seg[rt];
	sum[lson] += seg[rt] * (m - (m >> 1));
	sum[rson] += seg[rt] * (m >> 1);
	seg[rt] = 0;
}
void build(int l, int r, int rt) {
	seg[rt] = 0;
	if (l == r) {scanf("%lld", &sum[rt]); return;}
	int m = (l + r) >> 1;
	build(Lson); build(Rson);
	PushUp(rt);
}
void update(int L, int R, int add, int l, int r, int rt) {
	if (L <= l && r <= R) {
		seg[rt] += add;
		sum[rt] += add * (r - l + 1);
		return;
	}
	PushDown(rt, r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) update(L, R, add, Lson);
	if (m < R) update(L, R, add, Rson);
	PushUp(rt);
}
int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) return sum[rt];
	PushDown(rt, r - l + 1);
	int m = (l + r) >> 1, ret = 0;
	if (L <= m) ret += query(L, R, Lson);
	if (m < R) ret += query(L, R, Rson);
	return ret;
}
