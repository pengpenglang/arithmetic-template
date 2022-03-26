// 序列下标从1开始，LIS()返回长度，序列存在lis[]中
#define N 100100
int n, len, a[N], b[N], f[N];
int Find(int p, int l, int r) {
    int mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (a[p] > b[mid]) l = mid + 1;
        else r = mid - 1;
    }
    return f[p] = l;
}
int LIS(int lis[]) {
int len = 1;
f[1] = 1;
b[1] = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] > b[len]) b[++len] = a[i], f[i] = len;
        else b[Find(i, 1, len)] = a[i];
    }
    for (int i = n, t = len; i >= 1 && t >= 1; i--)
        if (f[i] == t)
            lis[--t] = a[i];
    return len;
}
