// xiang qi
// 1. 根据局面，找出所有能够将军的位置
// 2. 根据将的位置，判断是否结束
# include <iostream>
# include <string.h>
# include <stdio.h>

# define sync std::ios::sync_with_stdio( false )

# define testin freopen("in.txt", "r", stdin)

int board[11][10], n, gx, gy;
bool checkmate[11][10];
int px[9], py[9];

const int hx[] = {1,1,-1,-1,2,2,-2,-2};
const int hy[] = {2,-2,2,-2,1,-1,1,-1};
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

int Abs(int x) {
    return x<0 ? -x:x;
}

int countInterv(int x0, int y0, int x1, int y1) {
    int ret = 0;
    if (x0 == x1) {
        int inc = (y1-y0)/Abs(y1-y0);
        for (int i = y0; i != y1; i+=inc) {
            if (board[x0][i]) ++ret;
        }
        ret -= 1;
    }
    if (y0 == y1) {
        int inc = (x1-x0)/Abs(x1-x0);
        for (int i = x0; i != x1; i+=inc) {
            if (board[i][y0]) ++ret;
        }
        ret -= 1;
    }
    if (x0==x1 && y0==y1) ++ret;
    return ret;
}

int main()
{
    testin;
    //sync;

    while (scanf("%d%d%d", &n, &gx, &gy)) {
        if (!n && !gx && !gy) break;
        memset(board, 0, sizeof(board));
        memset(checkmate, false, sizeof(checkmate));
        char s[5];
        for (int i = 0; i < n; ++i) {
            scanf("%s%d%d", s, &px[i], &py[i]);
            board[px[i]][py[i]] = s[0];
        }
        for (int i = 0; i < n; ++i) {
            switch( board[ px[i] ][ py[i] ] ) {
                case 'G': {
                    for (int j = px[i]-1; j >= 1; --j) {
                        if (board[j][py[i]]) {
                            break;
                        }
                        if (j<=3) checkmate[j][py[i]] = true;
                    }
                    break;
                }
                case 'H': {
                    for (int j = 0; j < 8; ++j) {
                        int nx = px[i] + hx[j];
                        int ny = py[i] + hy[j];
                        if (1<=nx&&nx<=3 && 4<=ny&&ny<=6) {
                            // not hobbling...
                            if (!board[px[i] + hx[j]/2][py[i] + hy[j]/2]) {
                                checkmate[nx][ny] = true;
                            }
                        }
                    }
                    break;
                }
                case 'R': {
                    // vertical
                    if (4<=py[i]&&py[i]<=6) for (int j = px[i]-1; j >= 1; --j) {
                        if (board[j][py[i]]) {
                            break;
                        }
                        if (j<=3) checkmate[j][py[i]] = true;
                    }
                    // herizontal
                    if (1<=px[i]&&px[i]<=3) {
                        for (int j = py[i]+1; j <= 6; ++j) {
                            if (board[px[i]][j]) {
                                break;
                            }
                            if (j>=4) checkmate[px[i]][j] = true;
                        }
                        for (int j = py[i]-1; j >= 4; --j) {
                            if (board[px[i]][j]) {
                                break;
                            }
                            if (j<=6) checkmate[px[i]][j] = true;
                        }
                    }
                    break;
                }
                case 'C': {
                    for (int ii = 1; ii <= 3; ++ii) {
                        for (int j = 4; j <= 6; ++j) {
                            if (!board[ii][j] && countInterv(px[ii], py[i], ii, j) == 1) {
                                checkmate[ii][j] = true;
                            }
                        }
                    }
                    break;
                }
            }
        }
        bool ans = false;
        for (int i = 0; i < 4; ++i) {
            int nx = gx + dx[i], ny = gy + dy[i];
            if (1<=nx&&nx<=3 && 4<=ny&&ny<=6) {
                if (!checkmate[nx][ny]) {
                    ans = true;
                    break;
                }
            }
        }
        puts(ans==true ? "NO":"YES");
    }

    return 0;
}
