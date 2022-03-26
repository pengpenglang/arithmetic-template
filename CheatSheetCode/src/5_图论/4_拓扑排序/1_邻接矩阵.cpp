// 存图前记得初始化
// Ans存放拓排结果，G为邻接矩阵，deg为入度信息
// 排序成功返回1，存在环返回0
const int MAXN = "Edit";
int Ans[MAXN];		// 存放拓扑排序结果
int G[MAXN][MAXN];	// 存放图信息
int deg[MAXN];		// 存放点入度信息
void init() {
	memset(G, 0, sizeof(G));
	memset(deg, 0, sizeof(deg));
	memset(Ans, 0, sizeof(Ans));
}
void add_edge(int u, int v) {
	if (G[u][v]) return;
	G[u][v] = 1;
	deg[v]++;
}
bool Toposort(int n) {
	int tot = 0;
	queue<int> que;
	for (int i = 0; i < n; ++i)
		if (deg[i] == 0) que.push(i);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		Ans[tot++] = v;
		for (int i = 0; i < n; ++i)
			if (G[v][i] == 1)
				if (--deg[t] == 0) que.push(t);
	}
	if (tot < n) return false;
	return true;
}
