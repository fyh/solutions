// http://acm.buaa.edu.cn/contest/199/problem/E/

# include <stdio.h>
# include <iostream>
# include <algorithm>
using namespace std;

typedef long long int lli;

const int maxn = 205;

int n, m, q;
lli b[maxn][maxn];
int c[maxn];

int main()
{
    while (~scanf("%d%d%d", &n, &m, &q)) {
        lli ans = 0;
        for (int i = 0; i <= n; ++i) b[i][0] = 0;
        for (int i = 0; i <= m; ++i) b[0][i] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int x; scanf("%d", &x);
                b[i][j] = x;
                ans = max(ans, (lli)(x+q)%q);
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                b[i][j] += b[i-1][j];
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                lli cur = 0;
                for (int k = 1; k <= m; ++k) {
                    lli tmp = (b[j][k]-b[i-1][k] + q) % q;
                    ans = max(ans, cur);
                    if (cur + tmp >= q) {
                        cur = tmp;
                    } else cur += tmp;
                    ans = max(ans, cur);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
