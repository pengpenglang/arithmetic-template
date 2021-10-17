#define eps 1e-8
#define pi M_PI
#define zero(x) ((fabs(x)<eps?1:0))
#define sgn(x) (fabs(x)<eps?0:((x)<0?-1:1))
#define mp make_pair
#define X first
#define Y second

struct point {
    double x, y;
    point(double a = 0, double b = 0) {x = a; y = b;}
    point operator - (const point& b) const {
        return point(x - b.x, y - b.y);
    }
    point operator + (const point &b) const {
        return point(x + b.x, y + b.y);
    }
    // 两点是否重合
    bool operator == (point& b) {
        return zero(x - b.x) && zero(y - b.y);
    }
    // 点积(以原点为基准)
    double operator * (const point &b) const {
        return x * b.x + y * b.y;
    }
    // 叉积(以原点为基准)
    double operator ^ (const point &b) const {
        return x * b.y - y * b.x;
    }
    // 绕P点逆时针旋转a弧度后的点
    point rotate(point b, double a) {
        double dx, dy; (*this - b).split(dx, dy);
        double tx = dx * cos(a) - dy * sin(a);
        double ty = dx * sin(a) + dy * cos(a);
        return point(tx, ty) + b;
    }
    // 点坐标分别赋值到a和b
    void split(double &a, double &b) {
        a = x; b = y;
    }
};

struct line {
    point s, e;
    line() {}
    line(point ss, point ee) {s = ss; e = ee;}
};
