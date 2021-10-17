#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 100100;
struct Point {
    double x, y;
};
int n;
Point p[N], tmp[N];

bool cmp(Point a, Point b) {return a.x == b.x ? a.y < b.y : a.x < b.x;}
bool cmpy(Point a, Point b) {return a.y < b.y;}
double dis(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
double solve(int l, int r) {
    double d = 1e20;
    if (l == r) return d;
    if (l + 1 == r) return dis(p[l], p[r]);
    int mid = l + r >> 1;
    double d1 = solve(l, mid);
    double d2 = solve(mid + 1, r);
    d = min(d1, d2);
    int k = 0;
    for (int i = l; i <= r; i++)
        if (fabs(p[i].x - p[mid].x) <= d)
            tmp[k++] = p[i];
    sort(tmp, tmp + k, cmpy);
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++) {
            if (tmp[j].y - tmp[i].y > d) break;
            d = min(d, dis(tmp[i], tmp[j]));
        }
    return d;
}
int main() {
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        sort(p, p + n, cmp);
        printf("%.2lf\n", solve(0, n - 1) / 2);
    }
    return 0;
}
