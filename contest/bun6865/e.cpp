# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli n, m, k;

lli get(lli x, lli y) {
    lli ret = (n-x+1);
    ret *= y*(m+1) - (y+1)*y/2;
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin >> n >> m >> k) {
        lli ans = 0;
        for (int i = 1; (2*i+2) <= k && i <= n; ++i) {
            int y = min(k/2-i, m);
            ans += get(i, y);
        }
        cout << ans << endl;
    }

    return 0;
}
