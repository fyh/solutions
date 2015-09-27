# include <cstdio>
# include <cstring>
const int maxn = 505;
int n, k;
int c[maxn];
bool g[maxn][maxn];
bool vis[maxn];
int mark[maxn];
bool find(int u) {
    for (int v = 1; v <= n; ++v) if(g[u][v]){
        if (vis[v]) continue;
        vis[v] = true;
        if (mark[v]==-1 || find(mark[v])) {
            mark[v] = u;
            return true;
        }
    }
    return false;
}
# define testin freopen("in.txt", "r", stdin)
int main()
{
    testin;
    while (scanf("%d%d", &n, &k) != EOF) {
        memset(c, 0, sizeof(c[0])*(n+1));
        for (int i = 1; i <= n; ++i) memset(g[i], false, sizeof(g[i][0])*(n+1));
        for (int i = 0, x, y; i < k; ++i) {
            scanf("%d%d", &x, &y);
            g[x][y] = true;
        }
        int ans = 0;
        memset(mark, -1, sizeof(mark[0])*(n+1));
        for (int i = 1; i <= n; ++i) {
            memset(vis, false, sizeof(vis[0])*(n+1));
            if (find(i)) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
