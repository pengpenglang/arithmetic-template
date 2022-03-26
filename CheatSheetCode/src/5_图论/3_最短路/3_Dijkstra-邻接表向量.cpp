// MAXN: 点数最大值
// 求起点s到所有点x的最短路dis[x]
// 记得初始化
const int MAXN = "Edit";
const int INF = 0x3F3F3F3F;
vector<int> G[MAXN];
vector<int> GW[MAXN];
bool vis[MAXN];
int dis[MAXN];
void init(int n) {
	for (int i = 0; i < n; i++) {
		G[i].clear();
		GW[i].clear();
	}
}
void add_edge(int u, int v, int w) {
	G[u].push_back(v);
	GW[u].push_back(w);
}
void Dijkstra(int s, int n) {
	memset(vis, false, sizeof(vis));
	memset(dis, 0x3F, sizeof(dis));
	dis[s] = 0;
	for (int i = 0; i < n; i++) {
		int x;
		int min_dis = INF;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && dis[j] <= min_dis) {
				x = j;
				min_dis = dis[j];
			}
		}
		vis[x] = true;
		for (int j = 0; j < (int)G[x].size(); j++) {
			int y = G[x][j];
			int w = GW[x][j];
			dis[y] = min(dis[y], dis[x] + w);
		}
	}
}
