# include <bits/stdc++.h>
using namespace std;

const int maxn = 505;

int H, W;
char b[maxn][maxn];
int h[maxn][maxn];
int v[maxn][maxn];

int main()
{
    cin >> H >> W;
    for (int i = 1; i <= H; ++i) cin >> b[i]+1;

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (b[i][j] == '.' && b[i-1][j] == '.') {
                v[i][j] = 1;
            }
            v[i][j] += v[i][j-1];
            if (b[i][j] == '.' && b[i][j-1] == '.') {
                h[i][j] = 1;
            }
            h[i][j] += h[i][j-1];
        }
    }

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            v[i][j] += v[i-1][j];
            h[i][j] += h[i-1][j];
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int ans = 0;
        ans += v[r2][c2] - v[r1][c2] - v[r2][c1-1] + v[r1][c1-1];
        ans += h[r2][c2] - h[r1-1][c2] - h[r2][c1] + h[r1-1][c1];
        cout << ans << endl;
    }

    return 0;
}
