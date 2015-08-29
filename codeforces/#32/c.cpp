# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli n, m, s;

int main()
{
    cin >> n >> m >> s;

    lli dm = ((n+s-1)/s) * ((m+s-1)/s);
    lli x = (n+s-1)%s+1;
    lli y = (m+s-1)%s+1;
    lli ans = x * y * dm;
    cout << ans << endl;

    return 0;
}
