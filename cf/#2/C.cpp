# include <stdio.h>
# include <math.h>
# include <algorithm>

int x[3], y[3], r[3];
void read(void)
{
    for (int i = 0; i < 3; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
    }
}
double sq(double x) { return x * x; }
const double EPS = 1e-9;
// double compare
int dcmp(double x, double y, double eps=EPS)
{
    if (fabs(x-y) <= eps) return 0;
    return x-y < -eps ? -1:1;
}
bool cmp(const int a, const int b) {return r[a]<r[b];}
int t[3];
typedef struct fPoint2 {
    double x, y;
    fPoint2() :x(0),y(0) {}
    fPoint2(double _x, double _y) :x(_x), y(_y) {}
}fp2;
// dist^2
double d2(const fp2 &a, const fp2 &b) { return sq(a.x-b.x) + sq(a.y-b.y); }
// line cross line
int line_cross_line(double a1, double b1, double c1, double a2, double b2, double c2, fp2 &p)
{
    double ab = a1 * b2 - a2 * b1;
    if ( dcmp(ab, 0) == 0 ) return 0;
    double cb = -c1 * b2 + c2 * b1;
    double ac = -a1 * c2 + a2 * c1;
    p.x = cb / ab, p.y = ac / ab;
}
// Circumcenter
int cc(const fp2 &a, const fp2 &b, const fp2 &c, fp2 &p)
{
    double a1 = 2.0*(a.x - b.x), b1 = 2.0*(a.y - b.y), c1 = -(sq(a.x)-sq(b.x)+sq(a.y)-sq(b.y));
    double a2 = 2.0*(a.x - c.x), b2 = 2.0*(a.y - c.y), c2 = -(sq(a.x)-sq(c.x)+sq(a.y)-sq(c.y));
    return line_cross_line(a1, b1, c1, a2, b2, c2, p);
}
// common axis : CircleCrossCircle
void common_axis(fp2 p1, double r1, fp2 p2, double r2, double &a, double &b, double &c)
{
    double sx = p1.x + p2.x, mx = p1.x - p2.x;
    double sy = p1.y + p2.y, my = p1.y - p2.y;
    a = 2 * mx, b = 2 * my, c = -sx*mx - sy*my + sq(r1) - sq(r2);
}
int circle_cross_line(fp2 p0, double r, double a, double b, double c, fp2 &p1, fp2 &p2)
{
    double aa = a * a, bb = b * b, s = aa + bb;
    double d = r * r *s - sq(a*p0.x + b*p0.y + c);
    if ( d + EPS < 0 ) return 0;
    if ( d < EPS) d = 0; else d = sqrt( d );
    double ab = a * b, bd = b * d, ad = a * d;
    double xx = bb * p0.x - ab * p0.y - a * c;
    double yy = aa * p0.y - ab * p0.x - b * c;
    p1.x = ( xx - bd) / s; p1.y = ( yy + ad ) / s;
    p2.x = ( xx + bd ) / s; p2.y = ( yy - ad ) / s;
    if ( d > EPS ) return 2; else return 1;
}
// CircleCrossCircle
int circle_cross_circle(fp2 p1, double r1, fp2 p2, double r2, fp2 &q1, fp2& q2)
{
    double a, b, c; common_axis(p1, r1, p2, r2, a, b, c);
    return circle_cross_line(p1, r1, a, b, c, q1, q2);
}
void get_center(int i, int j, fp2 &c)
{
    fp2 p1, p2;
    p1.x = 1.0 * (r[i]*x[j] + r[j]*x[i]) / (r[i] + r[j]), p1.y = 1.0 * (r[i]*y[j] + r[j]*y[i]) / (r[i] + r[j]);
    p2.x = x[i]+1.0 * r[i] * (x[i]-x[j]) / (r[j] - r[i]), p2.y = y[i]+1.0 * r[i] * (y[i]-y[j]) / (r[j] - r[i]);
    c.x = 0.5 * (p1.x + p2.x), c.y = 0.5 * (p1.y + p2.y);
}
void solve(void)
{
    for (int i = 0; i < 3; ++i) t[i] = i;
    std::sort(t, t+3, cmp);

    if (r[t[0]] == r[t[1]] && r[t[1]] == r[t[2]]) {
        fp2 p;
        cc(fp2(x[t[0]], y[t[0]]), fp2(x[t[1]], y[t[1]]), fp2(x[t[2]], y[t[2]]), p);
        printf("%.6lf %.6lf\n", p.x, p.y);
    } else if (r[t[0]] == r[t[1]]) {
        fp2 p2; double r2;
        get_center(t[0], t[2], p2);
        r2 = sqrt( d2(fp2(x[t[0]], y[t[0]]), fp2(x[t[2]], y[t[2]])) ) * r[t[0]] * r[t[2]] / fabs( sq(r[t[0]]) - sq(r[t[2]]) );
        fp2 q1, q2;
        double a, b, c;
        a = 2*(x[t[0]] - x[t[1]]), b = 2*(y[t[0]] - y[t[1]]), c = -(x[t[0]] - x[t[1]])*(x[t[0]] + x[t[1]])-(y[t[0]] - y[t[1]])*(y[t[0]] + y[t[1]]);
        int T = circle_cross_line(p2, r2, a, b, c, q1, q2);
        if (T == 1) printf("%.6lf %.6lf\n", q1.x, q1.y);
        else if (T!=0){
            if (d2(q1, fp2(x[t[0]], y[t[0]])) < d2(q2, fp2(x[t[0]], y[t[0]]))) {
                printf("%.6lf %.6lf\n", q1.x, q1.y);
            } else {
                printf("%.6lf %.6lf\n", q2.x, q2.y);
            }
        }
    } else if (r[t[1]] == r[t[2]]) {
        fp2 p2; double r2;
        get_center(t[0], t[2], p2);
        r2 = sqrt( d2(fp2(x[t[0]], y[t[0]]), fp2(x[t[2]], y[t[2]])) ) * r[t[0]] * r[t[2]] / fabs( sq(r[t[0]]) - sq(r[t[2]]) );
        fp2 q1, q2;
        double a, b, c;
        a = 2*(x[t[2]] - x[t[1]]), b = 2*(y[t[2]] - y[t[1]]), c = -(x[t[2]] - x[t[1]])*(x[t[2]] + x[t[1]])-(y[t[2]] - y[t[1]])*(y[t[2]] + y[t[1]]);
        int T = circle_cross_line(p2, r2, a, b, c, q1, q2);
        if (T == 1) printf("%.6lf %.6lf\n", q1.x, q1.y);
        else if (T!=0){
            if (d2(q1, fp2(x[t[0]], y[t[0]])) < d2(q2, fp2(x[t[0]], y[t[0]]))) {
                printf("%.6lf %.6lf\n", q1.x, q1.y);
            } else {
                printf("%.6lf %.6lf\n", q2.x, q2.y);
            }
        }
    } else {
        fp2 p1; double r1;
        fp2 p2; double r2;
        get_center(t[0], t[1], p1);
        r1 = sqrt( d2(fp2(x[t[0]], y[t[0]]), fp2(x[t[1]], y[t[1]])) ) * r[t[0]] * r[t[1]] / fabs( sq(r[t[0]]) - sq(r[t[1]]) );
        get_center(t[0], t[2], p2);
        r2 = sqrt( d2(fp2(x[t[0]], y[t[0]]), fp2(x[t[2]], y[t[2]])) ) * r[t[0]] * r[t[2]] / fabs( sq(r[t[0]]) - sq(r[t[2]]) );
        fp2 q1, q2;
        int T = circle_cross_circle(p1, r1, p2, r2, q1, q2);
        if (T == 1) printf("%.6lf %.6lf\n", q1.x, q1.y);
        else if (T!=0){
            if (d2(q1, fp2(x[t[0]], y[t[0]])) < d2(q2, fp2(x[t[0]], y[t[0]]))) {
                printf("%.6lf %.6lf\n", q1.x, q1.y);
            } else {
                printf("%.6lf %.6lf\n", q2.x, q2.y);
            }
        }
    }
}
# define testin freopen("in.txt", "r", stdin)
int main()
{
    // testin;

    read();
    solve();
}
