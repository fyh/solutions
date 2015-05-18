# include <stdio.h>
# include <iostream>

using namespace std;

const int maxn = 1005;
int n;
int a[maxn][maxn];
int f[maxn][maxn][2];
bool ex;
int zx, zy;
char r[maxn];
int ans;

int calc(int x, int k)
{
    int ret = 0;
    while (x>0 && x%k==0) ++ret, x/=k;
    return ret;
}

int dp(int i, int j, int d)
{
    if (f[i][j][d] != -1) return f[i][j][d];
    f[i][j][d] = calc(a[i][j], d==0 ? 2:5);
    if (!i && !j) return f[i][j][d];
    int mn = 55*maxn;
    if (i > 0) mn = min(mn, dp(i-1, j, d));
    if (j > 0) mn = min(mn, dp(i, j-1, d));
    return f[i][j][d] += mn;
}

void pr(int x, int y, int k)
{
    if (!x && !y) return ;
    if (!x) {
        pr(x, y-1, k);
        putchar('R');
    } else if (!y) {
        pr(x-1, y, k);
        putchar('D');
    } else {
        if ( f[x-1][y][k] < f[x][y-1][k] ) {
            pr(x-1, y, k);
            putchar('D');
        } else {
            pr(x, y-1, k);
            putchar('R');
        }
    }
}

void dbg(int k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", f[i][j][k]);
        }
        printf("\n");
    }
    printf("\n");
}

# define testin freopen("in.txt", "r", stdin)
int main()
{
    testin;
    scanf("%d", &n);
    ex = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0) {
                a[i][j] = 10;
                ex = true;
                zx = i, zy = j;
            }
            f[i][j][0] = f[i][j][1] = -1;
        }
    }
    ans = min(dp(n-1,n-1,0), dp(n-1,n-1,1));
    // dbg(0), dbg(1);
    if (ex && ans>1) {
        printf("%d\n", 1);
        int x = 0, y = 0;
        while (x<zx || y<zy) {
            if (x < zx) putchar('D'), ++x;
            else putchar('R'), ++y;
        }
        while (x<n-1 || y<n-1) {
            if (x < n-1) putchar('D'), ++x;
            else putchar('R'), ++y;
        }
        putchar('\n');
    } else {
        printf("%d\n", ans);
        int k;
        if (f[n-1][n-1][0] < f[n-1][n-1][1]) k = 0;
        else k = 1;
        pr(n-1,n-1, k);
        putchar('\n');
    }

    return 0;
}
