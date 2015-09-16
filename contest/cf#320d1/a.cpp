# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli a, b;

int main()
{
    cin >> a >> b;

    if (a < b) cout << -1;
    else {
        if (a == b) cout << b;
        else {
            lli k1 = (a-b)/(2*b);
            double x1 = (a-b)/(2.0*k1);
            lli k2 = (a+b)/(2*b) - 1;
            double x2 = (a+b)/(2.0*(k2+1));
            double ans = min(x1, x2);
            cout << setprecision(10) << ans;
        }
    }

    cout << endl;

    return 0;
}
