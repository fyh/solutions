# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 5e4+5;

int n, r1, r2;

vector<int> g[maxn];
int f[maxn];

void dfs(int cur, int fa) {
    f[cur] = fa;
    for (int i = 0; i < g[cur].size(); ++i) {
        int v = g[cur][i];
        if (v != fa) dfs(v, cur);
    }
}

int main()
{
    cin >> n >> r1 >> r2;
    for (int i = 1; i <= n; ++i) {
        if (i == r1) continue;
        int v;
        cin >> v;
        g[i].push_back(v);
        g[v].push_back(i);
    }

    dfs(r2, 0);

    for (int i = 1; i <= n; ++i) {
        if (i == r2) continue;
        cout << f[i] << ' ';
    }
    cout << endl;

    return 0;
}
