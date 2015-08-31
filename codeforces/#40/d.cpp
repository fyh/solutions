# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 105;
const int maxk = 15;

int n, m, k;
int a[maxn][maxn];

int s[maxn][maxn][maxk];
int p[maxn][maxn][maxk];
int q[maxn][maxn][maxk];

char str[maxn];

void init() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        for (int j = 0; str[j]; ++j) {
            a[i][j+1] = str[j]-'0';
        }
    }
}

int path[maxn];

int main()
{
    init();
    int mod = k + 1;

    memset(s, -1, sizeof(s));

    for (int i = 1; i <= m; ++i) {
        s[n][i][ a[n][i]%mod ] = a[n][i];
    }
    for (int i = n-1; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            for (int r = 0; r < mod; ++r) {
                if (j > 1 && s[i+1][j-1][r]>=0) {
                    int t = s[i+1][j-1][r] + a[i][j];
                    int& cur = s[i][j][t%mod];
                    if (cur < t) {
                        cur = t;
                        p[i][j][t%mod] = +1;
                        q[i][j][t%mod] = r;
                    }
                }
                if (j < m && s[i+1][j+1][r]>=0) {
                    int t = s[i+1][j+1][r] + a[i][j];
                    int& cur = s[i][j][t%mod];
                    if (cur < t) {
                        cur = t;
                        p[i][j][t%mod] = -1;
                        q[i][j][t%mod] = r;
                    }
                }
            }
        }
    }
    int ans = -1, cur;
    for (int i = 1; i <= m; ++i) {
        if (ans < s[1][i][0]) {
            ans = s[1][i][0];
            cur = i;
        }
    }
    cout << ans << endl;

    if (ans >= 0) {
        int r = 0;
        for (int i = 1; i < n; ++i) {
            path[i] = p[i][cur][r];
            int tc = cur;
            cur = cur - p[i][cur][r];
            r = q[i][tc][r];
        }
        cout << cur << endl;
        for (int i = n-1; i >= 1; --i) {
            cout << (path[i]<0 ? 'L':'R');
        }
        cout << endl;
    }

    return 0;
}
