# include <bits/stdc++.h>
# define speedup cin.tie(0);ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int lli;

int n;

void init() {
    speedup;
    cin >> n;
    int pre = 0, cur = 0;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x >= pre) ans = max(ans, ++cur);
        else cur = 1;
        pre = x;
    }
    cout << ans << endl;
}

void solve() {
}

int main()
{
    init();
    solve();

    return 0;
}
