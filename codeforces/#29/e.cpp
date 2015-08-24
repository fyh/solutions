# include <bits/stdc++.h>
using namespace std;

const int maxn = 505;

int n, m;

struct ro{ int x, y, t; };
queue<ro> Q;
vector<int> e[maxn];

int d[maxn][maxn][2];
int p[maxn][maxn][2];
vector<int> pa, pb;

# define testin freopen("in.txt", "r", stdin)

int main()
{
    testin;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        e[x].push_back(y); e[y].push_back(x);
    }

    memset(d, -1, sizeof(d));
    d[1][n][0] = 0;
    Q.push(ro{1, n, 0});
    while (Q.size()) {
        ro t = Q.front(); Q.pop();
        cout << "d[" << t.x << ", " << t.y << ", " << t.t << "] = " << d[t.x][t.y][t.t] << ", " << p[t.x][t.y][t.t] << endl;
        if (!t.t) {
            for (int i = 0; i < e[t.x].size(); ++i) {
                int c = e[t.x][i];
                if (d[c][t.y][1] == -1) {
                    d[c][t.y][1] = d[t.x][t.y][0] + 1;
                    p[c][t.y][1] = t.x;
                    Q.push(ro{c, t.y, 1});
                }
            }
        } else {
            for (int i = 0; i < e[t.y].size(); ++i) {
                int c = e[t.y][i];
                if (c != t.x && d[t.x][c][0]==-1) {
                    d[t.x][c][0] = d[t.x][t.y][1] + 1;
                    p[t.x][c][0] = t.y;
                    Q.push(ro{t.x, c, 0});
                }
            }
        }
    }
    int ans = d[n][1][0];
    if (ans < 0) cout << -1 << endl;
    else {
        ans /= 2;
        cout << ans << endl;
        int a = n, b = 1;
        pa.push_back(a), pb.push_back(b);
        for (int i = 0; i < ans; ++i) {
            b = p[a][b][0]; pb.push_back(b);
            a = p[a][b][1]; pa.push_back(a);
        }
        for (int i = 0; i < pa.size(); ++i) {
            cout << pa[pa.size()-1-i] << ' ';
        }
        cout << endl;
        for (int i = 0; i < pb.size(); ++i) {
            cout << pb[pb.size()-1-i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
