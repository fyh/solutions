// ±¶Ôö·¨
# include <stdio.h>
# include <vector>
# include <algorithm>
const int maxn = 10005;
const int maxv = 15;

int N;
int fa[maxv][maxn];
int d[maxn], root;
std::vector<int> G[maxn];
void dfs(int u, int depth)
{
    d[u] = depth;
    for (int i = 0; i < G[u].size(); ++i) {
        dfs(G[u][i], depth+1);
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int ica = 0; ica < T; ++ica) {
        scanf("%d", &N);
        for (int i = 0; i <= N; ++i) fa[0][i] = 0;
        for (int i = 1; i <= N; ++i) G[i].clear();
        for (int i = 1, x, y; i < N; ++i) {
            scanf("%d%d", &x, &y);
            fa[0][y] = x;
            G[x].push_back(y);
        }
        for (int i = 1; i <= N; ++i) if (!fa[0][root=i]) break;
        dfs(root, 0);
        for (int i = 0; i+1 < maxv; ++i) {
            for (int j = 1; j <= N; ++j) {
                fa[i+1][j] = fa[i][ fa[i][j] ];
            }
        }
        int u, v;
        scanf("%d%d", &u, &v);
        if (d[u] < d[v]) std::swap(u, v);
        for (int i = 0; d[u]!=d[v]; ++i) {
            if ( (d[u]-d[v]>>i) & 0x1 ) u = fa[i][u];
        }
        if (u == v) printf("%d\n", u);
        else {
            for (int i = maxv-1; i >= 0; --i) {
                if (fa[i][u] != fa[i][v]) {
                    u = fa[i][u];
                    v = fa[i][v];
                }
            }
            printf("%d\n", fa[0][u]);
        }
    }

    return 0;
}

