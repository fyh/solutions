# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 15;
const double EPS = 1e-9;
const double INFd = 2e9;

int n, t;
int r[maxn];
double x[maxn], v[maxn], m[maxn];

bool cmp(const int &a, const int &b) {
    return x[a] <= x[b];
}

bool eqd(double a, double b) {
    return fabs(a-b) <= EPS;
}

double getCollisionTime(int a, int b) {
    if (v[a]<0 && v[b]>0) return INFd;
    if (eqd(x[b], x[a])) return INFd;
    return abs( (x[b]-x[a]) / (v[b]-v[a]) );
}

double getNextCollisions() {
    double ret = INFd;
    for (int i = 0; i+1 < n; ++i) {
        ret = min(ret, getCollisionTime(r[i], r[i+1]));
    }
    return ret;
}

void go(double tp, bool col) {
    for (int i = 0; i < n; ++i) {
        x[i] = x[i] + v[i] * tp;
    }
    if (col) {
        for (int i = 0; i+1 < n; ++i) {
                int p = r[i], q = r[i+1];
                if (eqd(x[p], x[q])) {
                    double a = (m[p]-m[q])*v[p] + 2*m[q]*v[q];
                    double b = (m[q]-m[p])*v[q] + 2*m[p]*v[p];
                    v[p] = a / (m[p]+m[q]), v[q] = b / (m[p]+m[q]);
                }
        }
    }
}

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> v[i] >> m[i];
        r[i] = i;
    }

    sort(r, r+n, cmp);

    double ct = 0;
    while (true) {
        double te = getNextCollisions();
        if (ct + te >= t) break;
        go(te, true);
        ct += te;
    }
    go(t - ct, false);
    for (int i = 0; i < n; ++i) printf("%.6lf\n", x[i]);

    return 0;
}
