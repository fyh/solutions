# include <stdio.h>
# include <string.h>
# include <iostream>
# include <algorithm>

using namespace std;

# define testin freopen("in.txt", "r", stdin)

/// f[i][j]: first i programmers write all j bugs methods count.
/// f[i+1][j] = sum{ f[i][j], f[i][j-x*v[i]]}

int n, m, b;
typedef int lli;

lli mod;


lli f[505][505];
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
        for (int j = 1; j <= m; ++j) {
            for (int k = a[i-1]; k <= b; ++k) {
                    f[j][k] = (f[j][k]+f[j-1][k-a[i-1]]) % mod;
            }
        }
    }
    lli ans = 0;
    for (int i = 0; i <= b; ++i) ans = (ans + f[m][i]) % mod;
    int tt = ans;
    printf("%d\n", tt);

    return 0;
}
