# include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;

int n;
vector<int> g[maxn];

int d[maxn]; // depth
int p[maxn]; // max depth
int ans;

bool cmp(const int &x, const int &y) {
    return p[x] >= p[y];
}

int dfs(int cur, int dep) {
    d[cur] = dep;
    p[cur] = 0;
    for (int i = 0; i < g[cur].size(); ++i) {
        int v = g[cur][i];
        p[cur] = max(p[cur], dfs(v, dep+1)+1);
    }
    if (g[cur].size() > 1) {
        sort(g[cur].begin(), g[cur].end(), cmp);
        int u = g[cur][0], v = g[cur][1];

        for (int i = 0; i < g[cur].size(); ++i) {
            int s = g[cur][i];
            if (s != u) {
                ans = max(ans, d[s]+p[s]+p[u]+1);
            } else {
                ans = max(ans, d[s]+p[s]+p[v]+1);
            }
        }
    }
    ans = max(ans, p[cur]+d[cur]);
    return p[cur];
}

int main()
{
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
        }
        ans = 0;
        dfs(1, 0);
        cout << ans << endl;
    }

    return 0;
}
