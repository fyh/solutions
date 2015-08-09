# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli n, d, m, l;

int main()
{
    while (cin >> n >> d >> m >> l) {
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            lli L = (i-1)*m+l;
            lli R = i * m;
            lli p = (L/d) * d + d;
            if (L<p&&p<R) {
                ok = false;
                cout << p << endl;
                break;
            }
        }
        if (ok) {
            lli L = (n-1) * m + l;
            cout << (L/d) * d + d << endl;
        }
    }

    return 0;
}
