# include <bits/stdc++.h>
using namespace std;

struct point2f {
    double x, y;
    point2f() {x = y = 0;}
    point2f(double _x, double _y) : x(_x), y(_y) {}
    point2f(const point2f &a) : x(a.x), y(a.y) {}
    void Pr() {
        cout << "point2f: " << x << "," << y << endl;
    }
};

struct segment {
    point2f a;
    point2f b;
    segment() {}
    segment(point2f _a, point2f _b) : a(_a), b(_b) {}
    segment(const segment &x) : a(x.a), b(x.b) {}
    void Pr() {
        cout << "seg:"
             << a.x << " " << a.y << ",  "
             << b.x << " " << b.y << endl;
    }
};

struct line {
    point2f a;
    point2f b;
    line() {}
    line(segment seg) : a(seg.a), b(seg.b) {}
    line(point2f _a, point2f _b) : a(_a), b(_b) {}
};

const double eps = 1e-8;

int dcmp(double x)
{
    if (fabs(x) < eps) return 0;
    return x>0 ? 1:-1;
}

int direction(point2f p1, point2f p2, point2f p3)
{
    double tmp = (p3.x-p1.x)*(p2.y-p1.y) - (p2.x-p1.x)*(p3.y-p1.y);
    return dcmp(tmp);
}

char isCross(point2f p1, point2f p2, point2f p3, point2f p4)
{
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);
    if (d1*d2 < 0 && d3*d4 < 0) return 1;
    return 0;
}

bool isOn(point2f p1, point2f p2, point2f p3)
{
    double x1 = p3.x - p1.x, y1 = p3.y - p1.y;
    double x2 = p3.x - p2.x, y2 = p3.y - p2.y;
    return x1 * y2 == x2 * y1 && x1*x2<=0 && y1*y2<=0;
}

char isCross2(point2f p1, point2f p2, point2f p3, point2f p4)
{
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);

    if (isOn(p1,p2,p3) || isOn(p1,p2,p4) || isOn(p3,p4,p1) || isOn(p3,p4,p2)) {
        return 1;
    }
    if (d1*d2 < 0 && d3*d4 < 0) return 1;
    return 0;
}

class Solver {
public:
    static bool cross(segment a, segment b) {
        return isCross(a.a, a.b, b.a, b.b);
    }
    static bool cross2(segment a, segment b) {
        return isCross2(a.a, a.b, b.a, b.b);
    }
    static bool cross(line a, segment b) {
        int d1 = direction(a.a, a.b, b.a);
        int d2 = direction(a.a, a.b, b.b);
        return d1 * d2 < 0 ;
    }
    static point2f mirrorIt(line l, point2f p) {
        double a, b, c;
        a = l.b.y - l.a.y;
        b = -l.b.x + l.a.x;
        c = -l.a.x * a - l.a.y * b;
        point2f ret;
        double d = a * a + b * b;
        ret.x = (b * b * p.x - a * a * p.x - 2 * a * b * p.y - 2 * a * c) / d;
        ret.y = (a * a * p.y - b * b * p.y - 2 * a * b * p.x - 2 * b * c) / d;
        return ret;
    }
    static point2f mirrorPoint(segment m, segment s, bool &isCr) {
        point2f mp = mirrorIt(line(m), s.a);
        point2f ret(0.5*(mp.x+s.a.x), 0.5*(mp.y+s.a.y));
        if (!cross2(m, segment(s.a, ret))) {
            isCr = false;
        } else {
            isCr = true;
        }
        return ret;
    }
};

point2f victor;
point2f peter;

segment wall;
segment mirror;

void init() {
    cin >> victor.x >> victor.y >> peter.x >> peter.y;
    cin >> wall.a.x >> wall.a.y >> wall.b.x >> wall.b.y;
    cin >> mirror.a.x >> mirror.a.y >> mirror.b.x >> mirror.b.y;
}

int main()
{
    init();

    segment con(victor, peter);
    if (!Solver::cross2(con, wall) && !Solver::cross2(con, mirror)) {
        puts("YES");
        return 0;
    } else if(Solver::cross(con, wall)) {
        if (!Solver::cross(line(mirror), con)) {
            bool isCr = true;
            point2f connectPoint = Solver::mirrorPoint(mirror, con, isCr);
            if (isCr && !Solver::cross(wall, segment(connectPoint, victor)) && !Solver::cross(wall, segment(connectPoint, peter))) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");

    return 0;
}


// (-2,0) (0,2)
