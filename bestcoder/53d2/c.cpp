# include <vector>
# include <string.h>
# include <iostream>
using namespace std;

const int maxn = 1005;

int n;
int d[maxn];
int cnt[maxn];
bool vis[maxn];
vector<int> g[maxn];

bool dfs(int x, int& tt) {
    vis[x] = true;
    ++tt;
    for (int i = 0; i < g[x].size(); ++i) {
        int t = g[x][i];
        if (!vis[t]) {
            dfs(t, tt);
        }
    }
}

int main()
{
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            d[i] = 0;
            g[i].clear();
        }
        bool ex = false;
        int tmp;
        for (int i = 0; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            if (u == v) {
                ex = true, tmp = u;
                continue;
            }
            ++d[u], ++d[v];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (ex) {
            d[tmp] -= 2;
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) ++cnt[ d[i] ];
        bool ok = false;
        memset(vis, false, sizeof(vis));
        int tt = 0;
        dfs(1, tt);
        if (tt == n) {
            if (ex) {
                if (cnt[1]==2&&cnt[2]+cnt[1]==n) {
                    ok = true;
                }
            } else {
                if (cnt[2] == n || cnt[1]==2&&cnt[3]==2&&cnt[1]+cnt[2]+cnt[3]==n || cnt[1]==1&&cnt[3]==1&&cnt[1]+cnt[2]+cnt[3]==n) {
                    ok = true;
                }
            }
        }
        cout << (ok ? "YES":"NO") << endl;
    }

    return 0;
}
