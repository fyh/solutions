# include <bits/stdc++.h>

# define testin freopen("in.txt", "r", stdin)

int n, m;
char s[55][55];

int lx, ly, rx, ry;

int main()
{
   // testin;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    lx = n, ly = m, rx = ry = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '*') {
                lx = std::min(lx, i);
                rx = std::max(rx, i);
                ly = std::min(ly, j);
                ry = std::max(ry, j);
            }
        }
    }
    for (int i = lx; i <= rx; ++i) {
        for (int j = ly; j <= ry; ++j) {
            putchar(s[i][j]);
        }
        puts("");
    }

    return 0;
}
