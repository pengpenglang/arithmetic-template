/**
 * @author pengpenglang
 * @brief 利用random造随机样例
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll a = 0, b = 1e5;  //规定生成随机数的范围

signed main(int argc, char *argv[]) {
    stringstream ss;
    ll seed = time(NULL);
    if (argc > 1) {  //如果传入了参数
        ss.clear();
        ss << argv[1];
        ss >> seed;  //把参数转换成整数赋值给seed
    }
    //rand_max=32767
    auto random = [] {  //加强随机数范围,生成数在$[a,b]$
        return a + rand() * rand() % (b - a + 1);
    };
    srand(seed);
    //以上为随机数初始化，请勿修改
    //下面利用利用rand()或者自定义的random()生成随机数
    cout << 1 << endl;  //单组循环、测试
    int len = random();
    string s = "";
    for (int i = 0; i < len; ++i)
        s += (char)(rand() % 25 + 'a');
    cout << s << endl;
    return 0;
}