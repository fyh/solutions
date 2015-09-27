# include <cstdio>
# include <cstring>
const int maxn = 100005;
int n,m;
int c[maxn];
bool a[maxn];
int id[maxn];
int right[maxn];
int cntId;
int cntEdge;
int first[maxn], next[maxn*2], wor[maxn*2];
void Add(int u, int v)
{
    int head = first[u];
    first[u] = ++cntEdge;
    next[cntEdge] = head;
    wor[cntEdge] = u ^ v;
}
void dfs(int u, int fa) {
    id[u] = ++cntId;
    for (int e = first[u]; e != -1; e = next[e]) {
        if (wor[e]!=(u^fa)) dfs(wor[e]^u, u);
    }
    right[ id[u] ] = cntId;
}
int lb(int x) {return x&-x;}
void Update(int x, int cc) {for(;x<=n;x+=lb(x)) c[x]+=cc;}
int GetSum(int x) { int r; for (r=0;x>0;x-=lb(x)) r+=c[x]; return r;}
# define testin freopen("in.txt", "r", stdin)
# define testout freopen("out.txt", "w", stdout)
int main()
{
    testin;
    testout;
    while (scanf("%d", &n) != EOF) {
        cntEdge = 0;
        memset(first, -1, sizeof(first));
        for (int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            Add(u, v); Add(v, u);
        }
        cntId = 0;
        dfs(1, -1);
        for (int i = 1; i <= n; ++i) c[i] = lb(i), a[i] = true;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            char od[5]; int x;
            scanf("%s%d", od, &x);
            if (od[0] == 'C') {
                a[x] = !a[x];
                Update(id[x], a[x]?1:-1);
            } else {
                printf("%d\n", GetSum(right[ id[x] ]) - GetSum(id[x]-1));
            }
        }
    }
    return 0;
}
