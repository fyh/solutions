# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


void area(double x, double y, double z) {
    double p = x + y + z;
    printf("%.10f\n", sqrt(0.0625*p*(p-2*x)*(p-2*y)*(p-2*z)) );
}

void solve()
{
    lli a[3], l;
    cin >> a[0] >> a[1] >> a[2] >> l;
    lli p2 = (a[0]+a[1]+a[2]+l);
    sort(a, a+3);
    lli d1 = a[1] - a[0];
    lli t = min(d1, l);
    a[0] += t;
    l -= t;
    if (l > 0) {
        lli d2 = a[2] - a[1];
        lli t2 = min(2*d2, l);
        a[0] += t2/2;
        a[1] += t2 - t2/2;
        l -= t2;
    }
    double x = a[0], y = a[1], z = a[2];
    if (l > 0) {
        x += l/3.0;
        y += l/3.0;
        z += l/3.0;
    }
    area(x,y,z);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
