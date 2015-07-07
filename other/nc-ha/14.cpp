# include <stdio.h>
# include <queue>
# include <utility>

const int maxn = 5005;

int n, m, t;
char mz[maxn][maxn];

int sx, sy;

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
            if (0<=nx&&nx<n && 0<=ny&&ny<m && !dep[nx][ny] && mz[nx][ny]!='*') {
                if (mz[nx][ny]=='P') return dep[p.first][p.second];
                dep[nx][ny] = dep[p.first][p.second] + 1;
                Q.push( std::make_pair(nx, ny) );
            }
        }
    }
    return maxn*maxn;
}

int main()
{
    while (~scanf("%d%d%d", &m, &n, &t)) {
        if (!n && !m && !t) break;
        for (int i = 0; i < n; ++i) {
            scanf("%s", mz[i]);
            for (int j = 0; j < m; ++j) {
                dep[i][j] = 0;
                if (mz[i][j] == 'S') {
                    sx = i, sy = j;
                }
            }
        }
        int T = bfs();
        puts(T<=t ? "YES":"NO");
    }

    return 0;
}
