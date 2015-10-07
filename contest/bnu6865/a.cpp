# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 2e9;

set<lli> s;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    for (lli i = 0; i*i <= maxn; ++i) s.insert(i*i);

    lli n;
    while (cin >> n) {
        bool ok = true;
        lli x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (ok && s.count(x) <= 0) ok = false;
        }
        puts(ok ? "Yes":"No");
    }

    return 0;
}
