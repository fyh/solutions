# include <stdio.h>
# include <string.h>
# include <queue>
# include <utility>

const int maxn = 5005;

int n = 10, m = 10;
char mz[maxn][maxn];

int sx = 0, sy = 1;
int gx = 9, gy = 8;

int dep[maxn][maxn];

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int bfs(void) {
    dep[sx][sy] = 1;
    typedef std::pair<int,int> pii;
    std::queue< pii > Q;
    Q.push( std::make_pair(sx,sy) );
    while (!Q.empty()) {
        pii p = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (0<=nx&&nx<n && 0<=ny&&ny<m && !dep[nx][ny] && mz[nx][ny]!='#') {
                if (nx==gx && ny==gy) return dep[p.first][p.second];
                dep[nx][ny] = dep[p.first][p.second] + 1;
                Q.push( std::make_pair(nx, ny) );
            }
        }
    }
    return maxn*maxn;
}

int main()
{
    while (~scanf("%s", mz[0])) {
        memset(dep, 0, sizeof(dep));
        for (int i = 1; i < n; ++i) {
            scanf("%s", mz[i]);
        }
        int T = bfs();
        printf("%d\n", T);
    }

    return 0;
}
