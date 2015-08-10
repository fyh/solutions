# include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

lli T, S, Q;

int main()
{
    cin >> T >> S >> Q;

    int ans = 1;
    while (S < T) {
        S = S * Q;
        if (S >= T) break;
        ++ans;
    }
    cout << ans << endl;

    return 0;
}
