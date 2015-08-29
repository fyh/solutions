# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


lli gcd(lli a, lli b) {
    return !b ? a:gcd(b, a%b);
}

const int maxn = 1e5+5;

lli n;
lli a[maxn];

bool jd(lli x) {
    while (x%2==0) x/=2;
    while (x%3==0) x/=3;
    return x == 1;
}

int main()
{
    cin >> n;
    lli c = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c = gcd(c, a[i]);
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        a[i]/=c;
        if (!jd(a[i])) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes":"No") << endl;

    return 0;
}
