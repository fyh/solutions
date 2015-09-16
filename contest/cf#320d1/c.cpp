# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 2e5+5;

int n;
double a[N];

double calc(double x) {
    double r1 = 0, r2 = 0;
    double c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        if (c1+a[i]-x <= 0) c1 = 0;
        else c1 += a[i]-x;
        r1 = max(r1, c1);
        if (c2+x-a[i] <= 0) c2 = 0;
        else c2 += x-a[i];
        r2 = max(r2, c2);
    }
    return max(r1, r2);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    double lo = 2e5, hi = -2e5;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        lo = min(lo, a[i]);
        hi = max(hi, a[i]);
    }
    for (int i = 0; i < 100; ++i) {
        double a1 = lo+(hi-lo)/3.0;
        double b1 = hi-(hi-lo)/3.0;

        if (calc(a1) > calc(b1)) lo = a1;
        else hi = b1;
    }
    cout << setprecision(9) << calc((lo+hi)*0.5) << endl;

    return 0;
}
