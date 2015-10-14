# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1005;
const int INF = 1005;

int n;
int a[maxn][maxn];
int f[maxn][maxn][2];
int h[2] = {2,5};

int cnt(int num, int k) {
    if (num == 0) return INF;
    int r = 0;
    while (num > 0 && num%h[k]==0) {
        num /= h[k];
        ++r;
    }
    return r;
}

int ans[maxn][maxn];

int dp2(int i, int j) {
    if (ans[i][j] != -1 || a[i][j]==0)     return ans[i][j];
    ans[i][j] = INF;
    if (i > 1) {
        ans[i][j] = min(ans[i][j], min(f[i-1][j][0],f[i-1][j][1]));
    }
    if (j > 1) {
        ans[i][j] = min(ans[i][j], min(f[i][j-1][0],f[i][j-1][1]));
    }
    if (i == 1 && j == 1) ans[i][j] = 0;
    ans[i][j] += min(f[i][j][0],f[i][j][1]);
    return ans[i][j];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            f[i][j][0] =  cnt(a[i][j], 0);
            f[i][j][1] =  cnt(a[i][j], 1);
        }
    }
    cout << dp2(n,n) << endl;

    //

    return 0;
}
