/*
ID: yajunwf1
LANG: C++11
TASK: castle
*/
# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

const int N = 55;

int m, n;
int a[N][N];
int f[N*N];
int C;
int co[N][N];

void init() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
}

int getBit(int x, int i) { return (x>>i) & 0x1; }

void dfs(int x, int y) {
    ++f[C];
    co[x][y] = C;
    if (!getBit(a[x][y], 0) && !co[x][y-1]) dfs(x, y-1);
    if (!getBit(a[x][y], 1) && !co[x-1][y]) dfs(x-1, y);
    if (!getBit(a[x][y], 2) && !co[x][y+1]) dfs(x, y+1);
    if (!getBit(a[x][y], 3) && !co[x+1][y]) dfs(x+1, y);
}

void solve() {
    int mx = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (co[i][j] == 0) {
                ++C;
                dfs(i, j);
                mx = max(mx, f[C]);
            }
        }
    }
    cout << C << endl << mx << endl;
    int mmx = 0, tx, ty, ch;
    for (int j = 1; j <= n; ++j) {
        for (int i = m; i >= 1; --i) {
            if (i>1 && getBit(a[i][j], 1) && co[i][j] != co[i-1][j]) {
                if (mmx < f[ co[i][j] ] + f[ co[i-1][j] ]) {
                    mmx = f[ co[i][j] ] + f[ co[i-1][j] ];
                    tx = i, ty = j, ch = 'N';
                }
            }
            if (j<n && getBit(a[i][j], 2) && co[i][j] != co[i][j+1]) {
                if (mmx < f[ co[i][j] ] + f[ co[i][j+1] ]) {
                    mmx = f[ co[i][j] ] + f[ co[i][j+1] ];
                    tx = i, ty = j, ch = 'E';
                }
            }
        }
    }
    cout << mmx << endl;
    cout << tx << ' ' << ty << ' ' << (char)ch << endl;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    rdio(castle);

    init();
    solve();

    return 0;
}
