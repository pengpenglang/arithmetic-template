/**
 * @author pengpenlang
 * @brief 外能头文件+多样例
 */
#include <bits/stdc++.h>
#pragma GCC optimize(2)  //开启$O^2$编译
#pragma G++ optimize(2)
// #define ONLINE_JUDGE
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(i, x, y) for (auto i = (x); i != (y + 1); ++i)
#define dep(i, x, y) for (auto i = (x); i != (y - 1); --i)
#ifndef ONLINE_JUDGE
#define de(...) cout << '[' << #__VA_ARGS__ << "] = " << __VA_ARGS__ << endl;
#else
#define de(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    /*处理每组样例*/
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("IO\\in.txt", "r", stdin);
    freopen("IO\\out.txt", "w", stdout);
    clock_t start, end;
    start = clock();
#endif
    solve();
#ifndef ONLINE_JUDGE
    end = clock();
    cout << endl
         << "Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}