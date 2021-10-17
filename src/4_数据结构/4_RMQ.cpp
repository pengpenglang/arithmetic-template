const int MAXN = 200000 + 100;
int mmax[MAXN][30], mmin[MAXN][30];
int a[MAXN], n, k;

void init() {
    for (int i = 1; i <= n; i++) {
        mmax[i][0] = mmin[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            mmax[i][j] = max(mmax[i][j - 1], mmax[i + (1 << (j - 1))][j - 1]);
            mmin[i][j] = min(mmin[i][j - 1], mmin[i + (1 << (j - 1))][j - 1]);
        }
}

// op=0/1 返回[l,r]最大/小值
int rmq(int l, int r, int op) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;
    if (op == 0) return max(mmax[l][k], mmax[r - (1 << k) + 1][k]);
    return min(mmin[l][k], mmin[r - (1 << k) + 1][k]);
}
