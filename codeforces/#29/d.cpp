# include <bits/stdc++.h>
using namespace std;

const int maxn = 305;

int n;
int lca[maxn][maxn];

int g[maxn][maxn], c[maxn];
int f[maxn], dep[maxn];
int cl;

int ca;
int ans[maxn*3];

void doit(int cur, int fa) {
    f[cur] = fa;
    dep[cur] = dep[fa] + 1;
    int cc = 0;
    for (int i = 0; i < c[cur]; ++i) {
        if (g[cur][i] != fa) {
            ++cc;
            doit(g[cur][i], cur);
        }
    }
    if (!cc) ++cl;
}

int getit(int x, int y) {
    while (x != y) {
        if (dep[x] > dep[y]) x = f[x];
        else if (dep[y] > dep[x]) y = f[y];
        else x = f[x], y = f[y];
    }
    return x;
}

bool work2(int y, int t) {
    if (y != t) {
        work2(f[y], t);
        ans[ca++] = y;
        if (ca > 2*n-1) {
            return false;
        }
    }
}

bool work(int x, int y) {
    int t = lca[x][y];

    while (true) {
        ans[ca++] = x;
        if (x == t) break;
        if (ca > 2*n-1) {
            return false;
        }
        x = f[x];
    }
    if (t != y) work2(f[y], t);
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        g[x][c[x]++] = y;
        g[y][c[y]++] = x;
    }
    doit(1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            lca[i][j] = lca[j][i] = getit(i, j);
        }
    }
    int cur = 1;
    bool ok = true;
    for (int i = 0; i < cl; ++i) {
        int x; cin >> x;
        if(ok && !work(cur, x)) ok = false;
        cur = x;
    }
    if(ok && !work(cur, 1)) ok = false;
    if (ok) {
        for (int i = 0; i < ca; ++i) {
            cout << ans[i] << ' ';
        }
    } else cout << -1 << endl;

    return 0;
}
