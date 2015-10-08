# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli k;

//2n+1

//(2n+1)*sqrt(3) = 2k

int main()
{
    cin >> k;

    lli n = 0;
    for (; (2*n+1)*(2*n+1)*3 <= 4*k*k; ++n) ; --n;
    lli ans = n*(n+1)*3 + 1;
    lli m = (k-1)/3;
    if (m>0 && m*3+1==k) {
        ans += (n+1)*3;
    }
    cout << ans << endl;

    return 0;
}
