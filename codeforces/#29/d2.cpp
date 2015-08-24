// priority dfs travel
// see this: http://m.blog.csdn.net/blog/qq574857122/36942757

# include <bits/stdc++.h>
using namespace std;

const int maxn = 305;

int n;
int fa[maxn];
int pr[maxn];
vector<int> g[maxn];
int a[maxn], m;

bool cmp(const int x, const int y) {
    return pr[x] <= pr[y];
}

void dfs(int cur, int fat) {
    fa[cur] = fat;
    for (int i = 0; i < g[cur].size(); ++i) {
        if (g[cur][i] != fat) {
            dfs(g[cur][i], cur);
        }
    }
}

int vis[maxn], lc;
int ans[maxn*3], cnt;

void dfs2(int cur, int fat) {
    ans[cnt++] = cur;
    bool hasSon = false;
    for (int i = 0; i < g[cur].size(); ++i) {
        if (g[cur][i] != fat) {
            hasSon = true;
            dfs2(g[cur][i], cur);
            ans[cnt++] = cur;
        }
    }
    if (!hasSon) vis[lc++] = cur;
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    // testin;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        g[x].push_back(y); g[y].push_back(x);
    }    dfs(1, 0);
    int x;
    while (cin >> x) {
        a[m++] = x;
        while (!pr[x]) {
            pr[x] = m;
            x = fa[x];
        }
    }
    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end(), cmp);
    }

    dfs2(1, 0);

    bool ok(true);
    for (int i = 0; i < m; ++i) if (a[i] != vis[i]) {
        ok = false;
        break;
    }

    if (!ok) cout << -1 << endl;
    else {
        for (int i = 0; i < cnt; ++i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
































