# include <stdio.h>
# include <algorithm>

const int maxn = 105;

int m, n;
int h[maxn][maxn];

int f[maxn][maxn];

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int dp(int x, int y) {
    if (f[x][y]) return f[x][y];
    f[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0<=nx&&nx<m&&0<=ny&&ny<n&&h[nx][ny]<h[x][y]) {
            f[x][y] = std::max(f[x][y], dp(nx,ny)+1);
        }
    }
    return f[x][y];
}

int main()
{
    while (~scanf("%d%d", &m, &n)) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &h[i][j]);
                f[i][j] = 0;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = std::max(ans, dp(i,j));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
