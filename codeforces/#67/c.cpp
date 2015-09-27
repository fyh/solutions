# include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int A, B;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

set<int> S;

void solve() {
    cin >> A >> B;
    int t = gcd(A, B);
    for (int i = 1; i*i <= t; ++i) {
        if (t%i == 0) S.insert(i), S.insert(t/i);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int lo, hi; cin >> lo >> hi;
        auto it = S.upper_bound(hi);
        --it;
        if (*it >= lo && *it <= hi) cout << *it << endl;
        else cout << -1 << endl;
    }
}

int main()
{
    solve();

    return 0;
}
