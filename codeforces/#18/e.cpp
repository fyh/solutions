// editorial : http://codeforces.com/blog/entry/463
# include <iostream>
# include <string.h>
# include <stdio.h>
using namespace std;

const int maxn = 505;
const int maxw = 30;

int n, m;
char fl[maxn][maxn];

int f[maxn][maxw][maxw];
int A[maxn][maxw][maxw], B[maxn][maxw][maxw];
int ans[maxn][2];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> fl[i];

    for (int r = 0; r < n; ++r) {
        for (int a = 0; a < 26; ++a) {
            for (int b = 0; b < 26; ++b) {
                if (a == b) continue;
                for (int i = 0; i < m; ++i) {
                    if ( ((i&0x1) && fl[r][i]-'a'!=b)
                            || (!(i&0x1) && fl[r][i]-'a'!=a) ) {
                        ++f[r][a][b];
                    }
                }
                if (r > 0) {
                    int mn = m * n * m, mp, mq;
                    for (int p = 0; p < 26; ++p) {
                        if (p == a) continue;
                        for (int q = 0; q < 26; ++q) {
                            if (q == p || q == b) continue;
                            if (mn > f[r-1][p][q]) {
                                mn = f[r-1][p][q];
                                mp = p, mq = q;
                            }
                        }
                    }
                    f[r][a][b] += mn;
                    A[r][a][b] = mp, B[r][a][b] = mq;
                }
            }
        }
    }

    int mn = m * n * m;
    for (int a = 0; a < 26; ++a) {
        for (int b = 0; b < 26; ++b) {
            if (a == b) continue;
            if (mn > f[n-1][a][b]) {
                mn = f[n-1][a][b];
                ans[n-1][0] = a, ans[n-1][1] = b;
            }
        }
    }

    cout << mn << endl;

    for (int i = n-1; i > 0; --i) {
        ans[i-1][0] = A[i][ ans[i][0] ][ ans[i][1] ], ans[i-1][1] = B[i][ ans[i][0] ][ ans[i][1] ];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j&0x1) putchar(ans[i][1]+'a');
            else putchar(ans[i][0]+'a');
        }
        puts("");
    }

    return 0;
}
