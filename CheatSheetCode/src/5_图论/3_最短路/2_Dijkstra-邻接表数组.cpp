// 点最大值: MAX_N  边最大值: MAX_E
// 求起点s到每个点x的最短路dis[x]
const int MAX_N = "Edit";	// 点数最大值
const int MAX_E = "Edit"; 
const int INF = 0x3F3F3F3F;
int tot;
int Head[MAX_N], vis[MAX_N], dis[MAX_N];
int Next[MAX_E], To[MAX_E], W[MAX_E];
void init() {
	tot = 0;
	memset(Head, -1, sizeof(Head));
}
void add_edge(int u, int v, int d) {
	W[tot] = d;
	To[tot] = v;
	Next[tot] = Head[u];
	Head[u] = tot++;
}
void Dijkstra(int s, int n) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3F, sizeof(dis));
	dis[s] = 0;
	for (int i = 0; i < n; i++) {
		int x, min_dis = INF;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && dis[j] <= min_dis) {
				x = j;
				min_dis = dis[j];
			}
		}
		vis[x] = 1;
		for (int j = Head[x]; j != -1; j = Next[j]) {
			int y = To[j];
			dis[y] = min(dis[y], dis[x] + W[j]);
		}
	}
}
