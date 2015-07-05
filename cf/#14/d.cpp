# include <bits/stdc++.h>

const int maxn = 205;
const int maxv = 15;

int n;
int u[maxn], v[maxn];
bool g[maxn][maxn];
int fa[maxn][maxv];
int dep[maxn];
int f[maxn];
int len[2];
bool vis[maxn];

void dfs(int cur, int fat, int sf) {
    vis[cur] = true;
    f[cur] = sf;
    if (fat!=-1) dep[cur] = dep[fat] + 1;
    else dep[cur] = 0;
    fa[cur][0] = fat;
    for (int i = 0; i < n; ++i) {
        if (g[cur][i] && !vis[i]) {
            dfs(i, cur, sf);
        }
    }
}

void build_query(void) {
    for (int i = 1; i < maxv; ++i) {
        for (int j = 0; j < n; ++j) {
            if (fa[j][i-1]!=-1) fa[j][i] = fa[ fa[j][i-1] ][i-1];
        }
    }
}

void move_up(int &x, int d) {
    for (int i = 0; i < maxv; ++i) {
        if ((d>>i)&0x1) {
            x = fa[x][i];
        }
    }
}

int qd(int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    int tx = x, ty = y;
    int df = dep[x] - dep[y];
    move_up(x, df);
    int lca = -1;
    for (int i = maxv-1; i >= 0; --i) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if (x != y) lca = fa[x][0];
    else lca = x;
    return dep[tx] + dep[ty] - 2 * dep[lca];
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    // testin;

    memset(g, false, sizeof(g));

    scanf("%d", &n);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        --u[i], --v[i];
        int x = u[i], y = v[i];
        g[x][y] = g[y][x] = true;
    }
    int ans = 0;    for (int e = 0; e < n-1; ++e) {
        len[0] = len[1] = 0;
        int x = u[e], y = v[e];
        g[x][y] = g[y][x] = false;
        for (int i = 0; i < n; ++i) {
            dep[i] = 0;
            f[i] = -1;
            memset(fa[i], -1, sizeof(fa[i]));
            vis[i] = false;
        }
        dfs(x, -1, 0);
        dfs(y, -1, 1);
        build_query();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && f[i] == f[j]) {
                    int t = f[i];
                    len[t] = std::max(len[t], qd(i,j));
                }
            }
        }
        ans = std::max(ans, len[0]*len[1]);
        g[x][y] = g[y][x] = true;
    }
    printf("%d\n", ans);

    return 0;
}
