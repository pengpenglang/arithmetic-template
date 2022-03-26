vector<pair<int, PII> > G;
void add_edge(int u, int v, int d) {
    G.pb(mp(d, mp(u, v)));
}
int Kruskal(int n) {
    init(n);
    sort(G.begin(), G.end());
    int m = G.size();
    int num = 0, ret = 0;
    for (int i = 0; i < m; i++) {
        pair<int, PII> p = G[i];
        int x = p.Y.X;
        int y = p.Y.Y;
        int d = p.X;
        if (!same(x, y)) {
            unite(x, y);
            num++;
            ret += d;
        }
        if (num == n - 1) break;
    }
    return ret;
}
