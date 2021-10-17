/**
 * @brief fread版快读支持所有整数类型,超多数据时表现优异
 */
struct ios_in {
    inline char gc() {
        const int MAXN = 1e5 + 100;  //读入字符串的最大长度（根据情况调整)
        static char buf[MAXN], *l, *r;
        return (l == r) && (r = (l = buf) + fread(buf, 1, MAXN, stdin), l == r) ? EOF : *l++;
    }
    template <typename _Tp>
    inline ios_in &operator>>(_Tp &x) {
        static char ch, sgn;
        for (sgn = 0, ch = gc(); !isdigit(ch); ch = gc()) {
            if (!~ch) return *this;
            sgn |= ch == '-';
        }
        for (x = 0; isdigit(ch); ch = gc())
            x = (x << 1) + (x << 3) + (ch ^ '0');
        sgn && (x = -x);
        return *this;
    }
} Cin;

Cin >> a;