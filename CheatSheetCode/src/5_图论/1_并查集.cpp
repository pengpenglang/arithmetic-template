const int MAXN = 128;
int n, fa[MAXN], ra[MAXN];
void init() {
    for (int i = 0; i <= n; i++) {
        fa[i] = i; ra[i] = 0;
    }
}
int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}
void unite(int x, int y) {
    x = find(x); y = find(y); if (x == y) return;
    if (ra[x] < ra[y]) fa[x] = y;
    else {
        fa[y] = x; if (ra[x] == ra[y]) ra[x]++;
    }
}
bool same(int x, int y) {
    return find(x) == find(y);
}
