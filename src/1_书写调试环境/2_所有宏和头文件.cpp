/**
 * @author pengpenglang
 * @brief ACM个人常用头文件与宏定义 
 */
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#pragma GCC optimize(2)  //开启o2编译
#pragma G++ optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")  //开启o3编译
#pragma G++ optimize(3, "Ofast", "inline")
// #define ONLINE_JUDGE
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, x, y) for (auto i = (x); i != (y + 1); ++i)
#define dep(i, x, y) for (auto i = (x); i != (y - 1); --i)
#ifndef ONLINE_JUDGE
#define de(...) cout << '[' << #__VA_ARGS__ << "] = " << __VA_ARGS__ << endl;
#else
#define de(...)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const int dir[][2]={{0,-1},{1,0},{0,1},{-1,0},{1,-1},{1,1},{-1,1},{-1,-1}};//上右下左、右上、右下、左下、左上
const double eps = 1e-8;
inline int sgn(double x) {  //和0比大于返1等于返0小于返-1
    return (x > eps) - (x < -eps);
}