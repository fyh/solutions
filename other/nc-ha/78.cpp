# include <stdio.h>

int m, n;
char s[15][15];
bool vis[15][16];

int cnt;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
void dfs(int x, int y) {
    if (vis[x][y]) return ;
    --cnt;
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0<=nx&&nx<m && 0<=ny&&ny<n && s[nx][ny]=='0') {
            dfs(nx, ny);
        }
    }
}

int main()
{
    while (~scanf("%d%d", &m, &n)) {
        for (int i = 0; i < m; ++i) scanf("%s", s[i]);
        cnt = m * n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == '1') --cnt;
                vis[i][j] = false;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (s[i][0] == '0') dfs(i, 0);
            if (s[i][n-1] == '0') dfs(i, n-1);
        }
        for (int i = 0; i < n; ++i) {
            if (s[0][i] == '0') dfs(0, i);
            if (s[m-1][i] == '0') dfs(m-1, i);
        }
        printf("%d\n", cnt);
    }

    return 0;
}
