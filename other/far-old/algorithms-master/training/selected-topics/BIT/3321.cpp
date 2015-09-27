//13684971	yajunw2013	3321	Time Limit Exceeded			C++	1423B	2014-12-03 15:44:13
# include <vector>
# include <cstdio>
# define rep(N) for(int i = 0; i < (N); ++i)
# define lb(x) ((x)&-(x))
# define testin freopen("in.txt", "r", stdin)
# define testout freopen("out.txt", "w", stdout)
using namespace std;
const int maxn = 100005;
int n, m;
vector<int> g[maxn];
int c[maxn];
bool a[maxn];
int id[maxn];
int y[maxn];
int cid;
void Update(int x, int cc)
{
    for (; x<=n; x+=lb(x)) c[x]+=cc;
}
int GetSum(int x)
{
    int r = 0;
    while (x>0) r+=c[x], x-=lb(x);
    return r;
}
void dfs(int cur, int fa)
{
    id[cur] = cid;
    rep(g[cur].size()) if(g[cur][i]!=fa) ++cid, dfs(g[cur][i], cur);
    y[id[cur]] = cid;
}
int main()
{
    testin;
    testout;
    int u, v;
    while (scanf("%d", &n)!=EOF) {
        rep(n+1) g[i].clear();
        rep(n-1) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        scanf("%d", &m);
        cid = 1;
        dfs(1,-1);
        rep(n+1) c[i] = lb(i), a[i] = true;
        char od[5];
        int x;
        rep(m) {
            scanf("%s%d", od, &x);
            if (od[0]=='C') {
                a[x] = !a[x];
                Update(id[x], a[x]?1:-1);
            } else {
                int ans1 = GetSum(id[x]-1);
                int ans2 = GetSum(y[id[x]]);
                printf("%d\n", ans2-ans1, ans2, ans1);
            }
        }
    }
    return 0;
}
