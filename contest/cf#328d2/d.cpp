# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

typedef pair<int,int> pii;

const int maxn = 123466;

int n, m;
vector<int> G[maxn];
vector<int> g[maxn];
int d[maxn], f[maxn];
bool mk[maxn];
int f2[maxn];

lli total;

void dfs(int cur, int fa, int fa2) {
    f[cur] = fa;
    d[cur] = d[fa] + 1;
    if (mk[cur]) {
        if (fa2 != 0) {
            G[fa2].push_back(cur);
            total += (d[cur]-d[fa2]) * 2;
        }
    }
    for (int i = 0; i < g[cur].size(); ++i) {
        int v = g[cur][i];
        if (v != fa) {
            if (mk[cur]) dfs(v, cur, cur);
            else dfs(v, cur, fa2);
        }
    }
}

int mx, ax;

pii chk(int cur) {
    if (G[cur].size() == 0) {
        return make_pair(0, -cur);
    }
    vector<pii> tmp;
    for (int i = 0; i < G[cur].size(); ++i) {
        int v = G[cur][i];
        pii p = chk(v);
        p.first += d[v] - d[cur];
        tmp.push_back(p);
    }
    if (tmp.size() > 1) {
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        if (tmp[0].first+tmp[1].first > mx) {
            mx = tmp[0].first+tmp[1].first;
            ax = min(-tmp[0].second, -tmp[1].second);
        } else if (tmp[0].first+tmp[1].first == mx) {
            ax = min(ax, min(-tmp[0].second, -tmp[1].second));
        }
    } else {
        if (tmp[0].first > mx) {
            mx = tmp[0].first;
            ax = min(cur, -tmp[0].second);
        } else if (tmp[0].first == mx) {
            ax = min(ax, min(cur, -tmp[0].second));
        }
    }
    return tmp[0];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int a0 = 0;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x; if (!a0) a0 = x;
        mk[x] = true;
    }

    if (m == 1) {
        cout << a0 << endl << 0 << endl;
        return 0;
    }

    dfs(a0, 0, 0);
    pii p = chk(a0);

    cout << ax << endl << total-mx << endl;

    return 0;
}
