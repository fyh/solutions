# include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 55;
const int maxl = 5005;
const int maxm = maxn * maxl;

int n, m;
int l[maxn];
lli a[maxn][maxl];
int b[maxm];
lli x[maxn], y[maxn], z[maxn], s[maxn];
bool vis[maxn];

int main()
{
    // freopen("in.txt", "r", stdin);

    lli mx = numeric_limits<lli>::min();

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        for (int j = 0; j < l[i]; ++j) cin >> a[i][j];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i]; --b[i];
        vis[ b[i] ] = true;
    }
    for (int i = 0; i < n; ++i) if (vis[i]) {
        for (int j = 0; j < l[i]; ++j) mx = max(mx, a[i][j]);
    }

    if (mx < 0) {
        cout << mx << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        x[i] = y[i] = z[i] = s[i] = 0;
        lli tx = 0, ty = 0, tz = 0;
        for (int j = 0; j < l[i]; ++j) {
            tx += a[i][j];
            s[i] += a[i][j];
            x[i] = max(x[i], tx);
            if (ty + a[i][j] < 0) {
                ty = 0;
            } else ty += a[i][j];
            y[i] = max(y[i], ty);
        }
        for (int j = l[i]-1; j >= 0; --j) {
            tz += a[i][j];
            z[i] = max(z[i], tz);
        }
        // cout << x[i] << "\t" << y[i] << "\t" << z[i] << "\t" << s[i] << endl;
    }
/*
    f[i] = max(y[i], g[i-1]+x[i]);
    g[i] = max(z[i], g[i-1]+s[i]);
*/
    lli cf = 0, cg = 0;
    for (int j = 0; j < m; ++j) {
        int i = b[j];
        cf = max(y[i], cg+x[i]);
        cg = max(z[i], cg+s[i]);
        mx = max(mx, cf);
        mx = max(mx, cg);
    }
    cout << mx << endl;

    return 0;
}
