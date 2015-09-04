// TLE
// O((m+n)lgm)
# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

# define C_GRAV (9.8)

const double EPS = 1e-5;

const int maxn = 1e4+5;
const int maxm = 1e5+5;

int n, v;
double alpha[maxn];
int m;
double x[maxm], y[maxn];
int r[maxm];
int cnt;
int id[maxm];
double up[maxm];

bool eql(const double &a, const double &b) {
    return abs(a - b) <= EPS;
}

bool cmp(const int &a, const int &b) {
    if (eql(x[a], x[b])) return y[a] >= y[b];
    return x[a] < x[b];
}

double get(const double cx, const double ang) {
    return (v*v*sin(2*ang)*cx-C_GRAV*cx*cx) / (2*v*v*cos(ang)*cos(ang));
}

double calc(int i) {
    double cy = y[i];
    double cx = x[i];
    double lo = 0, hi = atan(1.0) + EPS;
    if (get(cx, hi) < cy)  return hi;
    while (!eql(lo, hi) && lo < hi) {
        double mid = lo + (hi - lo) * 0.5;
        double vy = get(cx, mid);
        if (eql(vy, cy)) return mid;
        else if (vy < cy) lo = mid + EPS;
        else hi = mid - EPS;
    }
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(true);

    cin >> n >> v;
    for (int i = 0; i < n; ++i) {
        cin >> alpha[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> x[i] >> y[i];
    for (int i = 0; i < m; ++i) r[i] = i;

    sort(r, r+m, cmp);

    double pre = 0;
    for (int i = 0; i < m; ++i) {
        int c = r[i];
        double ang = calc(c);
        if (ang > pre && !eql(ang, pre)) {
            id[cnt] = c;
            up[cnt] = ang;
            pre = ang;
            ++cnt;
        }
    }

    for (int i = 0; i < n; ++i) {
        int tmp = upper_bound(up, up+cnt, alpha[i]) - up;
        if (tmp >= cnt) {
            cout << setprecision(6) << v*v*sin(2*alpha[i])/C_GRAV << " " << 0 << endl;
            // printf("%.9f %.9f\n", v*v*sin(2*alpha[i])/C_GRAV, 0);
        } else {
            int t = id[tmp];
            // printf("%.9f %.9f\n", x[t], (v*v*sin(2*alpha[i])*x[t]-C_GRAV*x[t]*x[t]) / (2*v*v*cos(alpha[i])*cos(alpha[i])) );
            cout << setprecision(6) << x[t] << " " << (v*v*sin(2*alpha[i])*x[t]-C_GRAV*x[t]*x[t]) / (2*v*v*cos(alpha[i])*cos(alpha[i])) << endl;
        }
    }

    return 0;
}
