/**
    http://codeforces.com/blog/entry/389
*/

# include <bits/stdc++.h>

typedef long long int lli;

const int maxn = 25;
const int maxt = 35;
const int maxh = 5;

int n, t, h;
lli f[maxn][maxt][maxh];

int main()
{
    h = 4;
    scanf("%d%d", &n, &t);

    int T = 2*t-1;

    if (n+2 < T) {printf("0\n"); return 0;}

    memset(f, 0, sizeof(f));

    for (int i = 0; i < h; ++i) {
        f[n][T][i] = 1;
    }

    for (int i = n-1; i >= 1; --i) {
        for (int j = 0; j <= T; ++j) {
            for (int k = 0; k < h; ++k) {
                f[i][j][k] = 0;
                if (j%2 == 0) {
                    for (int l = k+1; l < h; ++l) f[i][j][k] += f[i+1][j][l];
                    for (int l = 0; l < k; ++l) f[i][j][k] += f[i+1][j+1][l];
                } else {
                    for (int l = k+1; l < h; ++l) f[i][j][k] += f[i+1][j+1][l];
                    for (int l = 0; l < k; ++l) f[i][j][k] += f[i+1][j][l];
                }
            }
        }
    }

    lli ans = 0;
    for (int i = 0; i < h; ++i) ans += i * f[2][0][i];
    std::cout << ans << std::endl;

    return 0;
}
