# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

int n;
int a[maxn];
int f[maxn][2];
int g[maxn][2];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        f[i][0] = a[i] + max(f[i-1][0], f[i-1][1]);
        f[i][1] = -a[i] + f[i-1][1];
    }
    for (int i = n; i >= 1; --i) {
        g[i][0] = a[i] + max(g[i+1][0], g[i+1][1]);
        g[i][1] = -a[i] + g[i+1][1];
    }
    int ans = -1e9;
    for (int i = 1; i <= n; ++i) {
        ans = max(f[i][0]+g[i][0]-a[i], ans);
        ans = max(f[i][1]+max(g[i+1][0], g[i+1][1]), ans);
        ans = max(g[i][1]+max(f[i-1][1], f[i-1][0]), ans);
    }
    cout << ans << endl;

    return 0;
}
