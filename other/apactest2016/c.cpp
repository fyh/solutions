# include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int maxm = 1e4+5;

int d[maxn][maxn];
int u[maxm], v[maxm], c[maxm];

const int INF = 0x7FFFFFFF;

int main()
{
    freopen("C-large-practice.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    cin >> T;
    for (int ica = 1; ica <= T; ++ica) {
        cout << "Case #" << ica << ": " << endl;
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                d[i][j] = INF;
            }
            d[i][i] = 0;
        }
        for (int i = 0; i < M; ++i) {
            cin >> u[i] >> v[i] >> c[i];
            int x = u[i], y = v[i];
            d[y][x] = d[x][y] = min(d[x][y], c[i]);
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    if (d[j][i]!=INF && d[i][k]!=INF) d[j][k] = min(d[j][k], d[j][i]+d[i][k]);
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            if (d[ u[i] ][ v[i] ] != c[i]) {
                cout << i << endl;
            }
        }
    }

    return 0;
}
