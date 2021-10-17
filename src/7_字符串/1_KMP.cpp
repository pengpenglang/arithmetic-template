// 返回y中x的个数
int ne[N];
void initkmp(char x[], int m) {
    int i, j; j = ne[0] = -1; i = 0;
    while (i < m) {
        while (j != -1 && x[i] != x[j])
            j = ne[j];
        ne[++i] = ++j;
    }
}
int kmp(char x[], int m, char y[], int n) {
    int i, j, ans; i = j = ans = 0;
    initkmp (x, m);
    while (i < n) {
        while (j != -1 && y[i] != x[j]) j = ne[j];
        i++; j++;
        if (j >= m) {
            ans++; j = ne[j];
        }
    }
    return ans;
}