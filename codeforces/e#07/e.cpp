# include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+5;

int n, ans;
vector<int>G[maxn];

void dfs(int cur, int d, int fa) {
    bool vis = false;
    for (int i = 0; i < G[cur].size(); ++i) {
        int t = G[cur][i];
        if (t != fa) {
            vis = true;
            dfs(t, d+1, cur);
        }
    }
    if (!vis) ans = max(ans, d);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1, 0, 0);

    cout << ans << endl;

    return 0;
}
