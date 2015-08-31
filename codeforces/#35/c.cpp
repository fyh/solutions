# include <bits/stdc++.h>
# define input freopen("input.txt", "r", stdin)
# define output freopen("output.txt", "w", stdout)
using namespace std;
typedef long long int lli;

const int maxn = 2005;
const int maxk = 15;

int n, m, k;
int x[maxk], y[maxk];

int ans = 0, ax, ay;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
typedef pair<int,int> pii;
bool v[maxn][maxn];
void bfs() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            v[i][j] = false;
        }
    }
    int cnt = k;
    queue<pii> Q;
    for (int i = 0; i < k; ++i) {
        Q.push(make_pair(x[i],y[i]));
        v[x[i]][ y[i] ] = true;
    }
    if (cnt >= n*m) {
        cout << x[0] << ' ' << y[0] << endl;
        return ;
    }
    while (Q.size()) {
        pii p = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (1<=nx&&nx<=n && 1<=ny&&ny<=m && !v[nx][ny]) {
                Q.push(make_pair(nx, ny));
                v[nx][ny] = true;
                ++cnt;
                if (cnt == n*m) {
                    cout << nx << ' ' << ny << endl;
                    return ;
                }
            }
        }
    }
}

void solve2()
{
    int ans = -1, ax, ay;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int t = maxn * maxn;
            for (int z = 0; z < k; ++z) {
                t = min(t, abs(i-x[z])+abs(j-y[z]));
            }
            if (ans < t) {
                ans = t, ax = i, ay = j;
            }
        }
    }
    cout << ax << ' ' << ay << endl;
}

int main()
{
    input;
    output;

    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) cin >> x[i] >> y[i];

    // bfs();
    solve2();

    return 0;
}
