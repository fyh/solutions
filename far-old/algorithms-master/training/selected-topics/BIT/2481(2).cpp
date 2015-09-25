# include <cstring>
# include <cstdio>
# include <algorithm>
int n;
const int maxn = 100005;
int mx;
int x[maxn], y[maxn], r[maxn];
int c[maxn];
int ans[maxn];
bool cmp(const int i, const int j) {
    if (x[i] == x[j]) return y[j] < y[i];
    return x[i] < x[j];
}
bool judge(int i)
{
    if (i) {
        int u = r[i], v = r[i-1];
        if (x[u]==x[v] && y[u]==y[v]) return true;
    }
    return false;
}
int lb(int x) {return x&-x;}
int GetSum(int x) {
    int r; for (r = 0; x>0; x-=lb(x)) r+=c[x]; return r;
}
void inc(int x) { for (;x<=mx;x+=lb(x)) ++c[x];}
int main()
{
    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n), n) {
        mx = 1;
        for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]), mx = std::max(mx, ++y[i]);
        for (int i = 0; i < n; ++i) r[i] = i;
        std::sort(r, r+n, cmp);
        memset(c, 0, sizeof(c[0])*(mx+1));
        memset(ans, 0, sizeof(ans[0])*n);
        for (int i = 0; i < n; ++i) {
            int u = r[i];
            if (judge(i)) ans[u] = ans[ r[i-1] ];
            else ans[u] = GetSum(mx) - GetSum(y[u]-1);
            inc(y[u]);
        }
        for (int i = 0; i < n; ++i) {
            printf(i ? " %d":"%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
