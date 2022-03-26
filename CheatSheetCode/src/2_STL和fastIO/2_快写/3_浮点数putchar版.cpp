/**
 * @brief 浮点数putchar快写
 */

inline void dwrite(ll x) {  //用于输出整数部分
    if (x == 0) {
        putchar(48);
        return;
    }
    int bit[20], p = 0, i;
    for (; x; x /= 10) bit[++p] = x % 10;
    for (i = p; i > 0; --i) putchar(bit[i] + 48);
}
inline void write(double x, int k = 6) {  //不加位数,默认保留小数点后6位小数
    static int n = pow(10, k);            //和读入相反,这里我无法直接转化小数部分,先乘以n,就可以当做整数处理
    if (x == 0) {                         //x=0,保留的k位不断输出0;
        putchar('0'), putchar('.');
        for (int i = 1; i <= k; ++i) putchar('0');
        return;
    }
    if (x < 0) putchar('-'), x = -x;  //负数
    ll y = (ll)(x * n) % n;
    x = (ll)x;                //y表小数部分,x*n之后把小数部分截去再对n取余就可以得到需要保留的小数部分.
    dwrite(x), putchar('.');  //输出整数部分和小数点
    int bit[10], p = 0, i;
    for (; p < k; y /= 10) bit[++p] = y % 10;  //必须严格按照k位保留,否则就gg了
    for (i = p; i > 0; i--) putchar(bit[i] + 48);
}