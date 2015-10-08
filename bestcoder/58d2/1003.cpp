# include <algorithm>
# include <iostream>
# include <map>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

const lli M = 1e9+7;

int n;
lli a[maxn];
lli p[maxn];
map<lli, lli> m;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    p[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        p[i] = (p[i-1] * 2) % M;
    }

    int T; cin >> T;
    while (T--) {
        m.clear();
        cin >> n;
        lli ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ans = (ans + a[i] * p[n-1] % M ) % M;
            ans = (ans - m[ a[i] ] * a[i] % M * p[n-i-1] % M ) % M;
            m[ a[i] ] = (m[ a[i] ] + p[i]) % M;
        }
        ans = (ans%M + M) % M;
        cout << ans << endl;
    }

    return 0;
}
