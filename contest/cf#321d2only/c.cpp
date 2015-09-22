# include <bits/stdc++.h>
# define speedup cin.tie(0);ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;
int n, m;
int a[maxn];
vector<int> G[maxn];

int ans;

void dfs(int cur, int fa, int gm, int cm) {
    if (gm > m) return ;
    if (G[cur].size() <= 1) {
        if (gm <= m) {
            ++ans;
        }
    } else {
        for (int i = 0; i < G[cur].size(); ++i) {
            int v = G[cur][i];
            if (v == fa) continue;
            if (a[v]) dfs(v, cur, max(gm, cm+1), cm+1);
            else dfs(v, cur, gm, 0);
        }
    }
}

void init() {
    speedup;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    G[1].push_back(0);
    dfs(1,0,a[1],a[1]);
    cout << ans << endl;
}

void solve() {
}

int main()
{
    init();
    solve();

    return 0;
}
