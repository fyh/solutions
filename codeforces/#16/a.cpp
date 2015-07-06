# include <bits/stdc++.h>

int n, m;

const int maxn = 105;
char f[maxn][maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", f[i]);

    bool ok = true;
    int pre = -1;
    for (int i = 0; i < n; ++i) {
        int c = f[i][0];
        if (c == pre) {
            ok = false;
        }
        for (int j = 0; j < m; ++j) {
            if (f[i][j] != c) {
                ok = false;
            }
        }
        pre = c;
    }

    puts(ok ? "YES":"NO");

    return 0;
}
