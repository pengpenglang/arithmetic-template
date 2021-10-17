// pair<权值, 点>
// 记得初始化
const int MAXN = "Edit";
const int INF = 0x3F3F3F3F;
typedef pair<int, int> PII;
typedef vector<PII> VII;
VII G[MAXN];
int vis[MAXN], dis[MAXN];
void init(int n) {
	for (int i = 0; i < n; i++)
		G[i].clear();
}
void add_edge(int u, int v, int w) {
	G[u].push_back(make_pair(w, v));
}
void Dijkstra(int s, int n) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3F, sizeof(dis));
	dis[s] = 0;
	priority_queue<PII, VII, greater<PII> > q;
	q.push(make_pair(dis[s], s));
	while (!q.empty()) {
		PII t = q.top();
		int x = t.second;
		q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (int i = 0; i < (int)G[x].size(); i++) {
			int y = G[x][i].second;
			int w = G[x][i].first;
			if (!vis[y] && dis[y] > dis[x] + w) {
				dis[y] = dis[x] + w;
				q.push(make_pair(dis[y], y));
			}
		}
	}
}
