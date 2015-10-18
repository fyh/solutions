/*
ID: yajunwf1
LANG: C++11
TASK: skidesign
*/
# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

const int maxn = 1005;

int n;
int h[maxn];

int sq(int x) { return x*x; }

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    rdio(skidesign);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i];

    int ans = maxn*sq(100);
    for (int i = 0; i <= 100; ++i) {
        int lo = i, hi = lo+17;
        int cur = 0;
        for (int j = 1; j <= n; ++j) {
            if (h[j] > hi) cur += sq(h[j]-hi);
            else if (h[j] < lo) cur += sq(h[j]-lo);
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;

    return 0;
}
