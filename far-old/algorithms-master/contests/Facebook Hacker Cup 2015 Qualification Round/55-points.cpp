# include <stdio.h>
# include <string.h>
# include <queue>

# define testin  freopen("laser_maze.txt", "r", stdin);
# define testout freopen("out.txt", "w", stdout);

const int maxn = 105;
int M, N;
char inputMaze[maxn][maxn];
char maze[maxn][maxn][4];
bool vis[maxn][maxn][4];

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

class state{
public:
    int x, y, i;
    int step;
    state() {
        x = y = i = 0;
        step = -1;
    }
    state(int a, int b, int c, int d) : x(a), y(b), i(c), step(d) {}
    bool operator ==( const state &t) {
        return x==t.x&&y==t.y;
    }
};
state S, G;
std::queue< state > Q;
void ReadMaze();
void BuildMaze();
int RunMaze(state s, state g);
int main()
{
    testin;
    testout;
    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        ReadMaze();
        BuildMaze();
        int ans = RunMaze(S, G);
        printf("Case #%d: ", ica);
        if (ans < 0) printf("impossible\n");
        else printf("%d\n", ans);
    }

    return 0;
}

void ReadMaze()
{
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; ++i) scanf("%s", inputMaze[i]);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (inputMaze[i][j] == 'S') {
                S.y = i;
                S.x = j;
                S.i = 0;
                S.step = 0;
                inputMaze[i][j] = '.';
            } else if (inputMaze[i][j] == 'G') {
                G.y = i;
                G.x = j;
                inputMaze[i][j] = '.';
                //printf("Goal : %d %d\n", G.x, G>);
            }
        }
    }
}

void BuildMaze()
{
    memset(maze, '.', sizeof(maze));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                if ( inputMaze[j][k] == '#' ) {
                    maze[j][k][i] = '#';
                } else if ( inputMaze[j][k] == '^' ) {
                    for (int ii = j; ii >= 0; --ii) {
                        maze[ii][k][i] = '#';
                    }
                    inputMaze[j][k] = '>';
                } else if ( inputMaze[j][k] == '>' ) {
                    for (int ii = k; ii < N; ++ii) {
                        maze[j][ii][i] = '#';
                    }
                    inputMaze[j][k] = 'v';
                } else if ( inputMaze[j][k] == 'v' ) {
                    for (int ii = j; ii < M; ++ii) {
                        maze[ii][k][i] = '#';
                    }
                    inputMaze[j][k] = '<';
                } else if ( inputMaze[j][k] == '<' ) {
                    for (int ii = k; ii >= 0; --ii) {
                        maze[j][ii][i] = '#';
                    }
                    inputMaze[j][k] = '^';
                }
            }
        }
    }
}

int RunMaze(state s, state g)
{
    // 出生地不可达
    // if (maze[s.y][s.x][s.i] != '.')  return -2;
    // 目的不可达
    bool tmp = false;
    for (int i = 0; i < 4; ++i) {
        if (maze[g.y][g.x][i] == '.') {tmp = true; break;}
    }
    if (!tmp) return -3;
    // 出生=目的
    if (s.x==g.x && s.y==g.y) return 0;

    memset(vis, false, sizeof(vis));
    while (!Q.empty()) Q.pop();
    vis[s.y][s.x][s.i] = true;
    Q.push(s);
    while (!Q.empty()) {
        state cur = Q.front(); Q.pop();
        //printf("%d %d %d\n", cur.y, cur.x, cur.i);
        for (int i = 0; i < 4; ++i) {
            state nst = cur;
            nst.i = (nst.i + 1) % 4;
            nst.x += dx[i];
            nst.y += dy[i];
            nst.step = cur.step + 1;
            if (0<=nst.x&&nst.x<N&&0<=nst.y&&nst.y<M && maze[nst.y][nst.x][nst.i]=='.') {
                if (!vis[nst.y][nst.x][nst.i]) {
                    vis[nst.y][nst.x][nst.i] = true;
                    if (nst.x == g.x && nst.y == g.y) {
                        return nst.step;
                    }
                    Q.push(nst);
                }
            }
        }
    }
    return -1;
}
