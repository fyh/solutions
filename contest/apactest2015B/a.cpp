# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ull;
typedef pair<int,int> pii;

# define testin freopen("A-large.in", "r", stdin)
# define testout freopen("ou.txt", "w", stdout)

const int maxn = 505;
const int INF = 0x7FFFFFFF;

int N, M, K;
int d[maxn][maxn][24];
int dist[24][maxn][24];
bool inq[maxn][24];

bool ch[24];

int get(int S)
{
    ch[S] = true;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 24; ++j) {
            dist[S][i][j] = INF;
            inq[i][j] = false;
        }
    }
    dist[S][1][S] = 0;
    queue<pii> Q;
    Q.push( make_pair(1, S) );
    inq[1][S] = true;
    while (Q.size()) {
        pii cur = Q.front();
        Q.pop();
        inq[cur.first][cur.second] = false;
        int tmd = dist[S][cur.first][cur.second];
        if (tmd >= INF) continue;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < 24; ++j) {
                int &tmp = d[cur.first][i][cur.second];
                if (tmp == INF) continue;
                int ti = (tmp+cur.second)%24;
                if (tmp != INF && dist[S][i][ti] > tmd + tmp) {
                    dist[S][i][ti] = tmd + tmp;
                    if (!inq[i][ti]) {
                        Q.push(make_pair(i,ti));
                        inq[i][ti] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    testin;
    testout;
    int T;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> T;
    for (int ica = 1; ica <= T; ++ica) {
        cout << "Case #" << ica << ":";
        cin >> N >> M >> K;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                for (int t = 0; t < 24; ++t) {
                    if (i != j) d[i][j][t] = INF;
                    else d[i][j][t] = 0;
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;
            for (int j = 0; j < 24; ++j) {
                int w;
                cin >> w;
                d[x][y][j] = d[y][x][j] = min(d[x][y][j], w);
            }
        }
        memset(ch, false, sizeof(ch));
        for (int i = 0; i < K; ++i) {
            int D, S; cin >> D >> S;
            if (!ch[S]) get(S);
            int ans = INF;
            for (int i = 0; i < 24; ++i) ans = min(ans, dist[S][D][i]);
            if (ans == INF) ans = -1;
            cout << ' ' << ans;
        }
        cout << endl;
    }

    return 0;
}
