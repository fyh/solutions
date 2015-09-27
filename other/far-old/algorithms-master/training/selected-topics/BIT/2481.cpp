# include <cstdio>
# include <cstring>
# include <algorithm>
const int maxn = 100005;
int n;
int a[maxn], b[maxn], r[maxn], id[maxn];
int f[maxn], fc[maxn];
int c[maxn];
int ans[maxn];
int lb(int x) {
    return x & -x;
}
bool cmp(const int x, const int y) {
    if (a[x] == a[y]) return b[x] > b[y];
    return a[x] < a[y];
}
void inc(int x, int cc) {
    for (; x < maxn; x += lb(x)) c[x] += cc;
}
int GetSum(int x) {
    int r; for (r = 0; x > 0; x-=lb(x)) r += c[x];
    return r;
}
# define testin freopen("in.txt", "r", stdin)
# define testout freopen("out.txt", "w", stdout)
int main()
{
    testin;
   // testout;
    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i], &b[i]);
            ++a[i], ++b[i];
        }
        for (int i = 0; i < n; ++i) r[i] = i;
        std::sort(r, r+n, cmp);
        int m = 0;
        id[r[0]] = 0;
        f[0] = r[0];
        memset(fc, 0, sizeof(fc));
        ++fc[0];
        for (int i = 1; i < n; ++i) {
            int idx = r[i], pidx = r[i-1];
            if (a[idx]!=a[pidx] || b[idx]!=b[pidx]) ++m, f[m] = idx;
            ++fc[m];
            id[idx] = m;
        }
        ++m;
        memset(c, 0, sizeof(c));
        for (int i = 0; i < m; ++i) {
            ans[i] = GetSum(maxn-1) - GetSum( b[ f[i] ] - 1 );
            inc( b[ f[i] ], fc[i] );
        }
        for (int i = 0; i < n; ++i) {
            if (i) printf(" ");
            printf("%d", ans[ id[i] ]);
        }
        printf("\n");
    }
    return 0;
}
