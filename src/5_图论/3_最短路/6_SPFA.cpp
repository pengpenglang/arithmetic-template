// G[u] = mp(v, w)
// SPFA()返回0表示存在负环
const int MAXN = "Edit";
const int INF = 0x3F3F3F3F;
vector<pair<int, int> > G[MAXN];
bool vis[MAXN];
int dis[MAXN];
int inqueue[MAXN];
void init(int n) {
	for (int i = 0; i < n; i++)
		G[i].clear();
}
void add_edge(int u, int v, int w) {
	G[u].push_back(make_pair(v, w));
}
bool SPFA(int s, int n) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3F, sizeof(dis));
	memset(inqueue, 0, sizeof(inqueue));
	dis[s] = 0;
	queue<int> q;	// 待优化的节点入队
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		vis[x] = false;
		for (int i = 0; i < G[x].size(); i++) {
			int y = G[x][i].first;
			int w = G[x][i].second;
			if (dis[y] > dis[x] + w) {
				dis[y] = dis[x] + w;
				if (!vis[y]) {
					q.push(y);
					vis[y] = true;
					if (++inqueue[y] >= n) return 0;
				}
			}
		}
	}
	return 1;
}
