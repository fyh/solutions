# include <stdio.h>
# include <string.h>
const int maxn = 10005;
const int maxm = 10005;

int n, id, root, gh[maxn], gn[maxm], gv[maxm];
int u, v;
int p[maxn];
bool vis[maxn];
int find(int x) {return x==p[x] ? p[x]:p[x]=find(p[x]);}
void readGraph(void)
{
    id = 0;
    scanf("%d", &n);
    root = n*(n+1)/2;
    memset(gh+1, -1, sizeof(int)*n);
    for (int i = 1, x, y; i < n; ++i) {
        scanf("%d%d", &x, &y);
        gn[id] = gh[x];
        gv[id] = y;
        gh[x] = id++;
        root -= y;
    }
}
int tarjan(int x)
{
    vis[x] = true;
    if (x==u && vis[v]) return find(v);
    if (x==v && vis[u]) return find(u);
    for (int i = gh[x], r; i != -1; i = gn[i]) {
        if (!(r=tarjan(gv[i])))p[gv[i]] = x;
        else return r;
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int ica = 0; ica < T; ++ica) {
        readGraph();
        for (int i = 1; i <= n; ++i) p[i] = i;
        memset(vis+1, false, sizeof(bool)*n);
        scanf("%d%d", &u, &v);
        printf("%d\n", tarjan(root));
    }
    return 0;
}
