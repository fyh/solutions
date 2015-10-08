# include <cstdio>
# include <algorithm>
using namespace std;

const int maxn = 1005;

int n, m, k;
int a[maxn];
int s[maxn];
int f[maxn][maxn];

int dp(int c, int l) {
    if (f[c][l] != -1) return f[c][l];

    if (c == 0 || l == 0) return f[c][l] = 0;
    if (c <= l*m) return f[c][l] = s[c];

    f[c][l] = 0;
    int cur = 0;
    for (int i = m; i <= c; ++i) {
        cur = max(cur, s[c-i+m]-s[c-i]);
        f[c][l] = max(f[c][l], dp(c-i,l-1)+cur);
    }
    return f[c][l];
}

int main()
{
    while (~scanf("%d%d%d", &n, &m, &k)) {
        for (int i = 0; i <= n; ++i) for (int j = 0; j <= k; ++j) f[i][j] = -1;
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        s[0] = 0;
        for (int i = 1; i <= n; ++i) s[i] = s[i-1] + a[i];
        if (n <= m*k) printf("%d\n", s[n]); else printf("%d\n", dp(n, k));
    }

    return 0;
}
