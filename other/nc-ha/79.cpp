# include <stdio.h>

int n;
int a[25][25];

int main()
{
    while (~scanf("%d", &n)) {
        int cnt = 0;
        int xl = 1, yl = 1, xr = n, yr = n;
        while (cnt < n*n) {
            for (int i = xl; cnt<n*n && i <= xr; ++i) a[yl][i] = ++cnt;
            for (int i = yl+1; cnt<n*n && i <= yr; ++i) a[i][xr] = ++cnt;
            for (int i = xr-1; cnt<n*n && i >= xl; --i) a[yr][i] = ++cnt;
            for (int i = yr-1; cnt<n*n && i >= yl+1; --i) a[i][xl] = ++cnt;
            ++xl, ++yl, --xr, --yr;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j>1) putchar(' ');
                printf("%d", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
