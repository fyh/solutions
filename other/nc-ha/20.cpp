# include <stdio.h>
# include <algorithm>
# include <queue>

const int maxm = 505;
const int maxn = 35;

const int INF = 0x3f3f3f3f;

int m, n;

int g[maxn][maxn];
int d[maxn];
bool inq[maxn];

void init() {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            g[i][j] = (i==j ? 0:INF);
        }
        d[i] = INF;
        inq[i] = false;
    }
    d[0] = 0;

    for (int i = 0; i < m; ++i) {
        int f, t, c;
        scanf("%d%d%d", &f, &t, &c);
        g[f][t] = std::min(g[f][t], c);
    }
}

int solve() {
   // printf("%d\n", INF+INF);
    std::queue<int> Q;
    Q.push(0);
    inq[0] = true;
    while (!Q.empty()) {
        int t = Q.front(); Q.pop(); inq[t] = false;
        for (int i = 0; i <= n; ++i) {
            if (d[i] > d[t]+g[t][i] && !inq[i]) {
                inq[i] = true;
                Q.push(i);
                d[i] = d[t] + g[t][i];
            }
        }
    }
    printf("%d\n", d[n]==INF?-1:d[n]);
    return d[n];
}

int main()
{
    // freopen("in.txt", "r", stdin);
    while ((~scanf("%d%d", &m, &n)) && m && n) {
        init();
        solve();
    }

    return 0;
}
