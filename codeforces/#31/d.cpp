# include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

int W, H, n;
bool u[4][maxn][maxn];
bool c[maxn][maxn];
int cnt[maxn*maxn], m;

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

void dfs(int x, int y, int &ans) {
    if (x<1||x>n||y<1||y>n||c[x][y]) return ;
    c[x][y] = true;
    ++ans;
    for (int i = 0; i < 4; ++i) {
        if (!u[i][x][y]) {
            dfs(x+dx[i], y+dy[i], ans);
        }
    }
}

int main()
{
    cin >> W >> H >> n;

    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c) {
            if (b > d) swap(b, d);
            for (int j = b+1; j <= d; ++j) {
                u[0][a][j] = u[2][a+1][j] = true;
            }
        } else {
            if (a > c) swap(a, c);
            for (int j = a+1; j <= c; ++j) {
                u[1][j][b] = u[3][j+1][b] = true;
            }
        }
    }
    for (int i = 1; i <= W; ++i) {
        for (int j = 1; j <= H; ++j) {
            if (!c[i][j]) {
                int ans = 0;
                dfs(i, j, ans);
                cnt[m++] = ans;
            }
        }
    }
    sort(cnt, cnt+m);
    for (int i = 0; i < m; ++i) cout << cnt[i] << ' ';
    cout << endl;

    return 0;
}
