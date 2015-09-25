# include <cstdio>
const int maxn = 100005;
const int maxm = 1000005;
int n, m;
int fa[maxn + maxm];
bool isRoot[maxn + maxm];
int link[maxn];
int id;
int find(int x) {
    if (x != fa[x]) return fa[x]=find(fa[x]);
}
void join(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y) fa[x] = y;
}
void del(int x)
{
    link[x] = id++;
}
# define testin freopen("in.txt", "r", stdin)
int main()
{
    testin;
    int ica = 0;
    while (scanf("%d%d", &n, &m), n||m) {
        for (int i = 0; i < n+m; ++i) isRoot[i]=false, fa[i]=i;
        for (int i = 0; i < n; ++i) link[i] = i;
        char od[5];
        id = n;
        for (int i = 0, x, y; i < m; ++i) {
            scanf("%s%d", od, &x);
            if (od[0] == 'M') {
                scanf("%d", &y);
                join(link[x], link[y]);
            } else {
                del(x);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!isRoot[ find(link[i]) ]) {
                ++ans;
                isRoot[ find(link[i]) ] = true;
            }
        }
        printf("Case #%d: %d\n", ++ica, ans);
    }
    return 0;
}
