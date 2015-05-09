# include <stdio.h>
# include <string.h>
# include <iostream>
# include <algorithm>

using namespace std;

# define testin freopen("in.txt", "r", stdin)

/// f[i][j]: first i programmers write all j bugs methods count.
/// f[i+1][j] = sum{ f[i][j], f[i][j-x*v[i]]}

int n, m, b;
typedef long long int lli;

lli mod;

lli f[505][505];
lli g[505][505];
int a[505];


int main()
{
    testin;
    int mm;
    scanf("%d%d%d%d", &n, &m, &b, &mm);
    mod = mm;
    f[0][0] = 1;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= b; ++k) {
                g[j][k] = 0;
                for (int x = 0; x<=j&&x*a[i-1] <= k; ++x) {
                    g[j][k] = (g[j][k] + f[j-x][k-x*a[i-1]])%mod;
                }
            }
        }
        for(int j = 0; j <= m; ++j) {
            for (int k = 0; k <= b; ++k) {
                f[j][k] = g[j][k];
            }
        }
    }
    lli ans = 0;
    for (int i = 0; i <= b; ++i) ans = (ans + f[m][i]) % mod;
    int tt = ans;
    printf("%d\n", tt);

    return 0;
}
