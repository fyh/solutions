# include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

struct Point {
    double x, y;
    Point() {x = y = 0.0;}
    Point(const int &_x, const int &_y) : x(_x), y(_y) {}
};

struct Segline {
    Point a, b;
    Segline(Point &_a, Point &_b) : a(_a), b(_b) {}
    double dist2() {
        return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    }
    double dist() {
        return sqrt(dist2());
    }
};

bool cross(const Segline &a, const Segline &b) { ; }

Point s, t;

int n;
Point conv[35];
int main()
{
    cin >> s.x >> s.y >> t.x >> t.y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> conv[i].x >> conv[i].y;
    }

    bool cr = false;
    Segline di(s, t);
    for (int i = 0; i < n; ++i) {
        Segline tmp(conv[i], conv[(i+1)%n]);
        if (cross(di, tmp)) {
            cr = true;
            break;
        }
    }

    if (cr) {
        double ans = 200;
        ///
        ///
    } else {
        cout << di.dist() << endl;
    }

    return 0;
}
