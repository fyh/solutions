# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1005;
const int maxv = 16;

int n, m, k;
int d[maxn][maxn];
int r[maxn], cx[maxn], cy[maxn];
int kx[maxn], ky[maxn];

int id[maxn];
vector<int> son[maxn];
int f[maxn][maxv];
int dep[maxn];

void pre() {
    for (int i = 0; i < maxv; ++i) f[m][i] = m;
    for (int i = 1; i < maxv; ++i) {
        for (int j = 0; j <= m; ++j) {
            f[j][i] = f[ f[j][i-1] ][i-1];
        }
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    if (dep[x] != dep[y]) {
        int t = dep[x] - dep[y];
        for (int i = 0; i < maxv; ++i) {
            if ((t>>i)&0x1) {
                x = f[x][i];
            }
        }
    }
    for (int i = maxv-1; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i], y = f[y][i];
        }
    }
    if (x == y) return x;
    return f[x][0];
}

void dfs(int cur, int d) {
    dep[cur] = d;
    for (int i = 0; i < son[cur].size(); ++i) {
        dfs(son[cur][i], d+1);
    }
}

int calc(int x, int y)
{
    int t = lca(x, y);
    return -(dep[t] - dep[x] + dep[t] - dep[y]);
}

bool in(int x, int y) {
    if (r[x] >= r[y]) return false;
    lli dx = cx[x] - cx[y];
    lli dy = cy[x] - cy[y];
    lli dd = r[y];
    if (dx*dx+dy*dy < dd*dd) return true;
    return false;
}

bool din(int x, int y) {
    lli dx = kx[x] - cx[y];
    lli dy = ky[x] - cy[y];
    lli dd = r[y];
    if (dx*dx+dy*dy < dd*dd) return true;
    return false;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> kx[i] >> ky[i];
    for (int i = 0; i < m; ++i) cin >> r[i] >> cx[i] >> cy[i];
    r[m] = 2e9;

    for (int i = 0; i < m; ++i) {
        int fa = -1, fr = 2e9;
        for (int j = 0; j < m; ++j) {
            if (i != j) {
                if (in(i, j)) {
                    if (fr > r[j]) {
                        fr = r[j];
                        fa = j;
                    }
                }
            }
        }
        if (fa == -1) son[m].push_back(i), f[i][0] = m;
        else son[fa].push_back(i), f[i][0] = fa;
    }
    dfs(m, 0);
    pre();

    for (int i = 0; i < n; ++i) {
        int fa = -1, fr = 2e9;
        for (int j = 0; j < m; ++j) {
            if (din(i, j)) {
                if (fr > r[j]) {
                    fr = r[j];
                    fa = j;
                }
            }
        }
        id[i] = fa;
    }

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        cout << calc(id[x], id[y]) << endl;
    }

    return 0;
}
