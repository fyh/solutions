# include <bits/stdc++.h>

const int maxk = 105;

int N, K;

int maxL[maxk];
bool v[maxk][maxk];
bool ok[maxk][maxk][maxk];
int e[maxk][maxk];
int es[maxk][maxk][maxk];

void read() {
    scanf("%d%d", &N, &K);
}

// O(K + K^2 + 2*K^3)
void prep() {
    for (int x = 1; x <= K; ++x) maxL[x] = K;
    for (int y = 1; y <= K; ++y) {
        for (int x = 1; x <= K+1; ++x) {
            for (int len = 0; len <= K; ++len) {
                if (x + len - 1 > K) continue;
                ok[y][x][len] = true;
            }
        }
    }
    int cc = (K + 1) / 2;
    for (int x = 1; x <= K; ++x) {
        for (int y = 1; y <= K; ++y) {
            e[x][y] = abs(x-cc) + abs(y-cc);
        }
    }
    for (int x = 1; x <= K; ++x) {
        for (int y = 1; y <= K; ++y) {
            for (int len = 1; len <= K; ++len) {
                if (y + len - 1 > K) continue;
                es[x][y][len] = es[x][y][len-1] + e[x][y+len-1];
            }
        }
    }
}

const int INF = maxk * maxk * maxk;

void solve() {
    for (int ica = 0; ica < N; ++ica) {
        int T; scanf("%d", &T);
        int me = INF, mx, my;
        for(int x = 1; x <= K; ++x) {
            if (maxL[x] < T) continue;
            for (int y = 1; y <= K; ++y) {
                if (y + T - 1 > K) continue;
                if (ok[x][y][T] && me > es[x][y][T]) {
                    if (me > es[x][y][T])
                    me = es[x][y][T];
                    mx = x, my = y;
                }
            }
        }
        if (me != INF) printf("%d %d %d\n", mx, my, my+T-1);
        else printf("-1\n");
        for (int i = 0; i < T; ++i) {
            v[mx][my+i] = true;
        }
        // update maxL
        // update ok
        for (int x = K; x >= 1; --x) {
            for (int len = 1; len <= K; ++len) {
                if (x + len - 1 > K) continue;
                if (v[mx][x]) ok[mx][x][len] = false;
                else {
                    ok[mx][x][len] = ok[mx][x+1][len-1];
                    maxL[mx] = std::max(maxL[mx], len);
                }
            }
        }
    }
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    // testin;

    read();
    prep();
    solve();

    return 0;
}
