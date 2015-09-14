# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1005;

int n;
char s[maxn];

int f[maxn][maxn][2][2];

int dp(int l, int r, int x, int y) {
    if (f[l][r][x][y] != -1) return f[l][r][x][y];
    int n = r - l + 1;

    if (l > r) return maxn * maxn;

    int &c = f[l][r][x][y];
    if (n%2==0 && x==y) c = maxn*maxn;
    else if (n%2==1 && x!=y) c = maxn*maxn;

    if (n == 2) {
        if (s[l] == s[r]) c = 1;
        else if (s[l]==x+'0') c = 0;
        else c = maxn*maxn;
    } else if (n == 1) {
        c = (x==y ? 0:maxn*maxn);
    } else if (n == 0) {
        c = 0;
    } else {
        c = maxn * maxn;

        if (x == s[l]-'0') {
            c = min(c, dp(l+1, r, 1-x, y));
            c = min(c, dp(l+2, r, x, y) + dp(l, l+1, x, y));
        } else {
            c = min(c, dp(l+1, r, x, y)+1);
        }

        // c = min(c, dp(l+1, r, 1-x, y) + dp(l, l, x, x));
        // c = min(c, dp(l+2, r, x, y) + dp(l, l+1, x, y));
    }

    cout << l << ", " << r << "\t" << x << ", " << y << "\t" << c << endl;

    return c;
}

int main()
{
    cin >> n >> s+1;
    for (int i = 1; i <= n; ++i) s[i] -= '0';

    memset(f, -1, sizeof(f));

    int ans = min(dp(1, n, 0, 1-n%2), dp(1, n, 1, n%2));

    cout << (ans>=maxn*maxn ? -1:ans) << endl;

    return 0;
}
