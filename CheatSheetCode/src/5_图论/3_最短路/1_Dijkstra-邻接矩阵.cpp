// N为点数最大值 求s到所有点的最短路
// 要求边权值为非负数 模板为有向边
// dis[x]为起点到点x的最短路 inf表示无法走到
// 记得初始化
const int N = 100;	// 点数最大值
const int INF = 0x3f3f3f3f;
int G[N][N], dis[N];
bool vis[N];
void init(int n) {
	set(G, 0x3f);
}
void add_edge(int u, int v, int w) {
	G[u][v] = min(G[u][v], w);
}
void Dijkstra(int s, int n) {
	set(vis, 0);
	set(dis, 0x3f);
	dis[s] = 0;
	for (int i = 0; i < n; i++) {
		int x, minDis = INF;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && dis[j] <= minDis) {
				x = j;
				minDis = dis[j];
			}
		}
		vis[x] = 1;
		for (int j = 0; j < n; j++)
			dis[j] = min(dis[j], dis[x] + G[x][j]);
	}
}
