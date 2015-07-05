# include <bits/stdc++.h>

# define testin freopen("in.txt", "r", stdin)

const int maxn = 405;

int dis[maxn][maxn];

char s[maxn];

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int get(char ch) {
    switch(ch) {
        case 'R': return 2;
        case 'L': return 3;
        case 'U': return 0;
        case 'D': return 1;
    }
    return -1;
}

bool check(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int xi = x - dx[i];
        int yi = y - dy[i];
        if (dis[xi][yi] && dis[xi][yi]+1 < dis[x][y]) {
            return false;
        }
    }
    return true;
}

int main()
{
    // testin;

    scanf("%s", s);

    int sx = 200, sy = 200;
    dis[sx][sy] = 1;

    bool ok = true;

    for (int i = 0; s[i]; ++i) {
        int t = get(s[i]);
        int cd = dis[sx][sy];
        if (t != -1) {
            sx += dx[t];
            sy += dy[t];
            if (dis[sx][sy]) {
                ok = false;
                break;
            }
            dis[sx][sy] = cd + 1;
            if (check(sx, sy) == false) {
                ok = false;
                break;
            }
        }
    }

    puts(ok ? "OK":"BUG");

    return 0;
}
