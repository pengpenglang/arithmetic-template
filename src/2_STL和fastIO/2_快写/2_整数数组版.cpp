/**
 * @brief putchar进一步数组优化版快写，超多数据时表现优异
 */
struct ios_out {
    template <typename _Tp>
    inline void operator<<(_Tp &x) {
        const int MAXN = 1e3 + 100;  //存储数字的数组（根据情况调整）
        char F[MAXN];
        _Tp tmp = x >= 0 ? x : (putchar('-'), -x);
        int cnt = 0;
        while (tmp) {
            F[cnt++] = tmp % 10 + '0';
            tmp /= 10;
        }
        if (!cnt) {
            putchar('0');
            return;
        }
        while (cnt) putchar(F[--cnt]);
    }
} Cout;

Cout << a;  //不能输出回车