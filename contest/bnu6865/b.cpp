# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

int n;
lli a[maxn];
lli b[maxn];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    lli ans = 0;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> a[i];
        lli fact = 1;
        lli ans = 0;
        for (int i = 1; i < 10; ++i) {
            fact *= 10;
            for (int j = 0; j < n; ++j) {
                b[j] = a[j] % fact;
            }
            sort(b, b+n);
            for (lli j = 0; j < n; ++j) {
                int lc = lower_bound(b+j+1, b+n, fact-b[j]) - (b+j+1);
                ans += (n-j-1) - lc;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
