# include <stdio.h>
# include <algorithm>
# include <string.h>
const int maxn = 5005;
int w[maxn], h[maxn], id[maxn];
int cw, ch, n, m = 0;
int f[maxn];
int g[maxn];
bool ok(int i, int j) {
    return (w[i]>w[j] && h[i]>h[j]);
}
int dp(int k)
{
    if (f[k] != -1) return f[k];
    f[k] = 1;
    for (int i = 0; i < m; ++i) {
        if (ok(i,k) && dp(i)+1>f[k]) {
            f[k] = dp(i)+1;
            g[k] = i;
        }
    }
    return f[k];
}
void pr(int i)
{
    if (i < 0) return ;
    printf("%d ", id[i]);
    pr(g[i]);
}
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &cw, &ch);
    for (int i = 0; i < n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        if (x>cw && y>ch) {
            w[m] = x, h[m] = y, id[m] = i+1;
            ++m;
        }
    }
    memset(f, -1, sizeof(f[0])*(m+1));
    memset(g, -1, sizeof(g[0])*(m+1));
    int ans = 0, mi;
    for (int i = 0; i < m; ++i) {
        if (dp(i) > ans) {
            ans = dp(i);
            mi = i;
        }
    }
    printf("%d\n", ans);
    if (ans > 0) {
        pr(mi);
        printf("\n");
    }

    return 0;
}
