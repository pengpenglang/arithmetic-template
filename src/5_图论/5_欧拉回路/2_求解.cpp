#define MAXN 200
struct stack {
	int top, node[MAXN];
} s;

int G[MAXN][MAXN];	// 邻接矩阵
int n;	// 顶点个数

void dfs(int x) {
	int i;
	s.node[++s.top] = x;
	for (int i = 0; i < n; i++)
		if (G[i][x] > 0) {
			G[i][x] = G[x][i] = 0;
			dfs(i);
			break;
		}
}
void Fleury(int x) {
	int i, b;
	s.node[s.top = 0] = x;
	while (s.top >= 0) {
		b = 0;
		for (int i = 0; i < n; i++)
			if (G[s.node[s.top]][i] > 0) {
				b = 1;
				break;
			}
		if (b == 0) {
			printf("%d ", s.node[s.top] + 1);
			s.top--;
		}
		else {
			s.top--;
			dfs(s.node[s.top + 1]);
		}
	}
	printf("\n");
}

int main() {
	int i, j;
	int m, s, t; // 边数，读入的边的起点和终点
	int degree, num, start; // 每个顶点的度、奇度顶点个数、欧拉回路的起点
	scanf("%d%d", &n, &m);
	set(G, 0);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &s, &t)
		G[s - 1][t - 1] = G[t - 1][s - 1] = 1;
	}
	num = 0; start = 0;
	for (i = 0; i < n; i++) {
		degree = 0;
		for (j = 0; j < n; j++)
			degree += G[i][j];
		if (degree & 1) {
			start = i;
			num++;
		}
	}
	if (num == 0 || num == 2) Fleury(start);
	else puts("No Euler path");
	return 0;
}