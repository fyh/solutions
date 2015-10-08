# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# include <vector>
# include <map>
using namespace std;
typedef long long int lli;

const int maxn = 15;

int n;
int d[maxn][maxn];
vector<int> G[maxn];
vector<int> W[maxn];

void dfs(int cur, int fa, int dist, int &ans) {
    ans = max(ans, dist);
    for (int i = 0; i < G[cur].size(); ++i) {
        int v = G[cur][i];
        if (v == fa) continue;
        int w = W[cur][i];
        dfs(v, cur, dist+w, ans);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        G[x].push_back(y);
        G[y].push_back(x);
        W[x].push_back(w);
        W[y].push_back(w);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        dfs(i, 0, 0, ans);
    }
    cout << (ans*10 + ans*(ans+1)/2) << endl;

    return 0;
}
