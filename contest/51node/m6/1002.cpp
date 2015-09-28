# include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;

lli mod = 1000000007;

// 1 3 3 7

lli n;
void pre(lli k)
{
    lli a[15];
    lli f[15];
    f[0] = 0, f[1] = 1;
    a[0] = 0;
    for (int i = 2; i < 15; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
    for (int i = 1; i <= k; ++i) {
        a[i] = a[i-1] | f[i];
        if (i == k) cout << a[i] << endl;
    }
}

lli mp(lli m)
{
    lli ans = 1;
    lli tmp = 2;
    while (m > 0) {
        if (m&0x1) ans = (ans*tmp)%mod;
        m >>= 1;
        tmp = (tmp*tmp)%mod;
    }

    return (ans+mod-1)%mod;
}


lli getH() {
    return  (lli) floor( (n*log(0.5*(1+sqrt(5.0))) - 0.5*log(5.0)) / log(2.0) ) + 1;
}

void solve()
{
    if (n < 2) cout << n << endl;
    else if (n < 10) pre(n);
    else cout << mp(getH())  << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        cin>>n;
        solve();
    }

    return 0;
}
