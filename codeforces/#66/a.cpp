# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


lli x, y, z, k;

int main()
{
    cin >> x >> y >> z >> k;

    if (x-1 + y-1 + z-1 <= k) {
        cout << x*y*z << endl;
    } else {
        lli a = 1, b = 1, c = 1;
        for (;;) {
            if (k > 0 && a < x) ++a, --k;
            if (k > 0 && b < y) ++b, --k;
            if (k > 0 && c < z) ++c, --k;
            if (k <= 0 || (a>=x && b>=y && c>=z)) break;
        }
        cout << a*b*c << endl;
    }

    return 0;
}
