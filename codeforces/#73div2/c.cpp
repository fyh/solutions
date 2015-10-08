# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli gcd(lli a, lli b) { return !b ? a:gcd(b, a%b); }

lli x, y;

int main()
{
    cin >> x >> y;
    lli lcm = x * y / gcd(x, y);

    lli c1 = lcm / x - 1;
    lli c2 = lcm / y - 1;

    if (x < y) ++c2;
    else ++c1;

    if (c1 == c2) cout << "Equal" << endl;
    else cout << (c1 < c2 ? "Masha":"Dasha") << endl;

    return 0;
}
