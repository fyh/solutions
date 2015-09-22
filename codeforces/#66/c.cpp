# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 105;
const int maxa = 26+5;
const int INF = 1005 * 1 * maxn;

char s[maxn];
int t[maxa][maxa];

int k, m, n;

int f[maxn][maxn][maxa];

int dp() {
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int o = 'a'; o <= 'z'; ++o) {
                f[i][j][o] = -INF;
                if (!i) {
                    if (!j) f[i][j][s[j]] = 0;
                    else f[i][j][ s[j] ] = f[i][j-1][ s[j-1] ] + t[ s[j-1] ][s[j]];
                } else if (j) {
                    for (int p = 'a'; p <= 'z'; ++p) {
                        if (o == s[j]) {
                            f[i][j][o] = max(f[i][j-1][p]+t[p][o], f[i][j][o]);
                        } else {
                            f[i][j][o] = max(f[i-1][j-1][p]+t[p][o], f[i][j][o]);
                        }
                    }
                } else {
                    if (i == 1) f[i][j][o] = 0;
                }
            }
        }
    }
    int ans = -INF;
    for (int i = 0; i <= k; ++i) {
        for (int j = 'a'; j <= 'z'; ++j) {
            ans = max(ans, f[i][m-1][j]);
        }
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> s >> k >> n;
    m = strlen(s);
    for (int i = 0; i < n; ++i) {
        char x, y; int w; cin >> x >> y >> w;
        t[x][y] = w;
    }
    cout << dp() << endl;

    return 0;
}
