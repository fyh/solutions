# include <iostream>
# include <algorithm>
# include <string.h>

using namespace std;

typedef long long int lli;

const int maxn = 65;

lli f[maxn][maxn];
int n;

lli dp(int p, int q) {
    if (f[p][q] != -1) return f[p][q];
    if (p == 1) return f[p][q] = 1;

    f[p][q] = 0;
    for (int i = 1; i+3 <= q; ++i) {
        f[p][q] += dp(p-1, i);
    }
    return f[p][q];
}


int main()
{
    memset(f, -1, sizeof(f));
    while (cin >> n) {
        lli ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += dp(i+1, n+3);
        }
        cout << ans << endl;
    }
    return 0;
}
