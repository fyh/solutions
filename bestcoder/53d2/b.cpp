# include <vector>
# include <iostream>
using namespace std;

const int maxn = 1005;

int n;
vector<int> g[maxn];
int cd[maxn];

void dfs(int cur, int fa, int dep) {
    ++cd[dep];
    for (int i = 0; i < g[cur].size(); ++i) {
        int v = g[cur][i];
        if (v != fa) {
            dfs(v, cur, dep+1);
        }
    }
}

int main()
{
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) g[i].clear(), cd[i] = 0;
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0, 1);
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (cd[i]>1&&cd[i+1]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES":"NO") << endl;
    }

    return 0;
}
