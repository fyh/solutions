# include <stdio>
# include <cstring>

const int maxn = 1e5+5;

int n, m, k, q;
int r[maxn], c[maxn];

void init() {
    memset(r, false, sizeof(r[0])*(n+1));
    memset(c, false, sizeof(c[0])*(m+1));
    for (int i = 0; i < k; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        r[x] = 1, c[y] = 1;
    }
    for (int i = 1; i <= n; ++i) r[i] += r[i-1];
    for (int i = 1; i <= m; ++i) c[i] += c[i-1];
}

void solve() {
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (r[x2]-r[x1-1]==x2-x1+1 || c[y2]-c[y1-1]==y2-y1+1) puts("Yes");
        else puts("No");
    }
}

int main()
{
    while (~scanf("%d%d%d%d", &n, &m, &k, &q)) {
        init();
        solve();
    }

    return 0;
}
