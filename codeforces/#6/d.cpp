# include <algorithm>
# include <stdio.h>

const int maxn = 15;
const int maxh = 20;

int n, a, b;
int h[maxn];
int g[maxn][maxh][maxh];

const int INF = 233;

int pre[maxh][maxh][maxh];

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++i) {scanf("%d", &h[i]); ++h[i];}
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < maxh; ++j)  {
            for (int k = 0; k < maxh; ++k) {
                g[i][j][k] = INF;
            }
        }
    }
    g[1][h[1]][h[2]] = 0;
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j <= h[i-1]; ++j) {
            for (int k = 0; k <= h[i]; ++k) {
                if (g[i-1][j][k] >= INF) continue;
                int lb = (j+b-1) / b;
                int ub = std::max(lb, std::max((k+a-1)/a, (h[i+1]+b-1)/b));
                for (int l = lb; l <= ub; ++l) {
                    int x = std::max(0, k-l*a);
                    int y = std::max(0, h[i+1]-l*b);
                    if (g[i][x][y] > g[i-1][j][k] + l) {
                        g[i][x][y] = g[i-1][j][k] + l;
                        pre[i][x][y] = (j<<8)|k;
                    }
                }
            }
        }
    }
    printf("%d\n", g[n-1][0][0]);
    int x = 0, y = 0, i = n-1;
    while (i > 1) {
        int l = pre[i][x][y];
        int t = g[i][x][y] - g[i-1][l>>8][l&0xff];
        for (int j = 0; j < t; ++j) printf("%d ", i);
        x = (l>>8)&0xff, y = (l&0xff);
        --i;
    }

    return 0;
}
