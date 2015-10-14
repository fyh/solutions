# include <bits/stdc++.h>
using namespace std;
# define speedup cin.tie(0), ios_base::sync_with_stdio(false)
typedef long long int lli;

const int maxn = 105;
const int maxc = 256;

int n, m;
char b[maxn][maxn];
int r[maxn][maxc], c[maxn][maxc];

int main()
{
    speedup;

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> b[i]+1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ++r[i][ b[i][j] ];
            ++c[j][ b[i][j] ];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (r[i][ b[i][j] ] == c[j][ b[i][j] ] && r[i][ b[i][j] ] == 1) {
                cout << b[i][j] ;
            }
        }
    }
    cout << endl;

    return 0;
}
