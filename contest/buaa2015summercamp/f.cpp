# include <stdio.h>
# include <algorithm>
using namespace std;

const int maxn = 305;
const int maxq = 1e5+5;
const int INF = 10 * maxn * maxq;

int n, m, q;
int e[maxn][maxn];
int t[maxq], x[maxq], y[maxq];

bool v[maxn];
int ans[maxq];

int main()
{
    // freopen("in.txt", "r", stdin);

    while (~scanf("%d%d%d", &n, &m, &q)) {
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                e[j][i] = e[i][j] = (i==j ? 0:INF);
            }
            v[i] = false;
        }

        for (int i = 0; i < m; ++i) {
            int U, V, w; scanf("%d%d%d", &U, &V, &w);
            e[U][V] = e[V][U] = min(e[U][V], w);
        }

        for (int i = 0; i < q; ++i) {
            y[i] = 0;
            scanf("%d%d", &t[i], &x[i]);
            if (t[i] == 1) scanf("%d", &y[i]);
            else if (!v[ x[i] ]) {
                y[i] = 1;
                v[ x[i] ] = true;
            }
        }

        for (int i = 1; i <= n; ++i) if (!v[i]) {
            for (int j = 1; j <= n; ++j) if (!v[j]) {
                for (int k = 1; k <= n; ++k) if (!v[k]) {
                    e[j][k] = min(e[j][k], e[j][i]+e[i][k]);
                }
            }
        }

        for (int i = q-1; i >= 0; --i) {
            if (t[i] == 1) {
                int tmp = e[ x[i] ][ y[i] ];
                ans[i] = (tmp>=INF ? -1:tmp);
            } else if (y[i] == 1) {
                int from = x[i];
                for (int k = 1; k <= n; ++k) if (!v[k]) {
                    for (int j = 1; j <= n; ++j) if (!v[j]) {
                        e[ k ][ from ] = e[ from ][ k ] = min( e[from][k], e[from][j] + e[j][k]);
                    }
                }
                for (int k = 1; k <= n; ++k) if (!v[k]) {
                    for (int j = 1; j <= n; ++j) if (!v[j]) {
                        e[k][j] = min(e[k][j], e[k][from] + e[from][j]);
                    }
                }
                v[ x[i] ] = false;
            }
        }
        for (int i = 0; i < q; ++i) {
            if (t[i] == 1) printf("%d\n", ans[i]);
        }
    }

    return 0;
} 
