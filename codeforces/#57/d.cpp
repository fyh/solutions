# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 1e5+5;

int n;
vector<int> G[N];
vector<int> L[N];

void dfs(int cur, int fa, lli len, lli &mx) {
    if (G[cur][0] == fa && G[cur].size()==1) {
        mx = max(mx, len);
    } else {
        for (int i = 0; i < G[cur].size(); ++i) {
            int x = G[cur][i];
            if (x != fa) {
                dfs(x, cur, len+L[cur][i], mx);
            }
        }
    }
}

int main()
{
    lli ans = 0;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back(v); G[v].push_back(u);
        L[u].push_back(w); L[v].push_back(w);
        ans += w*2;
    }

    lli mx = 0;
    dfs(1, 0, 0, mx);
    cout << ans - mx << endl;

    return 0;
}
