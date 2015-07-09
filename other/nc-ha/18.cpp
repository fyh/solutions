# include <stdio.h>

int m, n;
char s[55][55];
bool vis[55][55];
int cnt;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
void dfs(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0<=nx&&nx<m && 0<=ny&&ny<n && s[nx][ny]=='.' && !vis[nx][ny]) {
            vis[nx][ny] = true;
            ++cnt;
            dfs(nx, ny);
        }
    }
}
int main()
{
    while (~scanf("%d%d", &m, &n)) {
        for (int i = 0; i < m; ++i) scanf("%s", s[i]);
        int sx, sy;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == '@') {
                    sx = i, sy = j;
                    cnt = 1;
                }
                vis[i][j] = false;
            }
        }
        dfs(sx, sy);
        printf("%d\n", cnt);
    }

    return 0;
}
