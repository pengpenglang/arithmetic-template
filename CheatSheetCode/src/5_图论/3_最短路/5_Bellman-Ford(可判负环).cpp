// 求出起点s到每个点x的最短路dis[x]
// 存在负环返回1 否则返回0
// 记得初始化
const int MAX_N = "Edit";	// 点数最大值
const int MAX_E = "Edit";	// 边数最大值
const int INF = 0x3F3F3F3F;
int From[MAX_E], To[MAX_E], W[MAX_E];
int dis[MAX_N], tot;
void init() {tot = 0;}
void add_edge(int u, int v, int d) {
	From[tot] = u;
	To[tot] = v;
	W[tot++] = d;
}
bool Bellman_Ford(int s, int n) {
	memset(dis, 0x3F, sizeof(dis));
	dis[s] = 0;
	for (int k = 0; k < n - 1; k++) {
		bool relaxed = 0;
		for (int i = 0; i < tot; i++) {
			int x = From[i], y = To[i];
			if (dis[y] > dis[x] + W[i]) {
				dis[y] = dis[x] + W[i];
				relaxed = 1;
			}
		}
		if (!relaxed) break;
	}
	for (int i = 0; i < tot; i++)
		if (dis[To[i]] > dis[From[i]] + W[i])
			return 1;
	return 0;
}
