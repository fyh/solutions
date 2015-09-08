# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli h, w;
lli area, x, y;

int main()
{
    cin >> h >> w;

    for (int i = 0; i <= 30; ++i) {
        lli tx = 1 << i;
        if (tx > w) break;
        double lo = tx*4.0/5, up = tx*5.0/4;
        if (lo<=h) {
            lli ty = h>up ? (lli)up:h;
            if (area < tx*ty) {
                x = ty, y = tx;
                area = x * y;
            }
        }
    }

    for (int i = 0; i <= 30; ++i) {
        lli tx = 1 << i;
        if (tx > h) break;
        double lo = tx*4.0/5, up = tx*5.0/4;
        if (lo<=w) {
            lli ty = w>up ? (lli)up:w;
            if (area < tx*ty) {
                x = tx, y = ty;
                area = x * y;
            }
        }
    }

    cout << x << ' ' << y << endl;

    return 0;
}
