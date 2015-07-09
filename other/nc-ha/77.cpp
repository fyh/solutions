# include <stdio.h>

int m, n;
int a[55][55];

bool jd(int x, int y) {
    for (int i = 1; i <= n; ++i) if (a[x][i]>a[x][y]) return false;
    for (int i = 1; i <= m; ++i) if (a[i][y]<a[x][y]) return false;
    return true;
}

int main()
{
    while (~scanf("%d%d", &m, &n)) {
        for (int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (jd(i,j)) printf("%d %d\n", i, j), ++cnt;
            }
        }
        if (!cnt) puts("No Point");
        puts("");
    }

    return 0;
}
