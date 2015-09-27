# include <stdio.h>
# include <vector>
const int maxn = 10005;
const int maxm = 5;
std::vector <int> G[maxn];
std::vector <int> Q[maxn];
int root;
int N;
int q[maxm], m;
int ans[maxm];
int p[maxn];
bool vis[maxn];
int find(int x) {return x==p[x] ? p[x]:p[x]=find(p[x]);}
void tarjan(int u)
{
    vis[u] = true;
    for (int i = 0, Idx, v; i < Q[u].size(); ++i) {
        Idx = Q[u][i];
        v = u ^ q[ Idx ];
        if (vis[v]) ans[Idx] = find(v);
    }
    for (int i = 0, v; i < G[u].size(); ++i) {
        tarjan(v = G[u][i]);
        p[v] = u;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int ica = 0; ica < T; ++ica) {
        scanf("%d", &N);
        root = (N+1)*N/2;
        for (int i = 1; i <= N; ++i) G[i].clear();
        for (int i = 1; i <= N; ++i) Q[i].clear();
        for (int i = 1, x, y; i < N; ++i) {
            scanf("%d%d", &x, &y);
            G[x].push_back(y); root -= y;
        }
        m = 1;
        for (int i = 0; i < m; ++i) ans[i] = 0;
        int x, y;
        scanf("%d%d", &x, &y); q[0] = x^y;
        Q[x].push_back(0);
        Q[y].push_back(0);
        for (int i = 1; i <= N; ++i) vis[i] = false;
        for (int i = 1; i <= N; ++i) p[i] = i;
        tarjan(root);
        for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}
