# include <bits/stdc++.h>
using namespace std;
# define speedup cin.tie(0), ios_base::sync_with_stdio(false)
typedef long long int lli;

const int maxn = 1e4+5;

int n, m, k;
int a[maxn];

int main()
{
    speedup;

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (n%2 == 0) {
        cout << 0 << endl;
        return 0;
    }

    int mx = a[0];
    for (int i = 0; i < n; ++i) if (i%2==0) mx = min(mx, a[i]);

    lli ans = k;
    lli c = n/2+1;
    ans *= m/c;

    if (m < c) ans = 0;

    cout << min(ans, (lli)mx) << endl;

    return 0;
}
