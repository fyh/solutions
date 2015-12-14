# include <bits/stdc++.h>
using namespace std;
# define speedup cin.tie(0), ios_base::sync_with_stdio(false)

typedef long long int lli;

int n, m;

int main()
{
    speedup;

    cin >> n >> m;

    m %= (n+1)*n/2;
    for (int i = 1; i <= n; ++i) {
        if (m < i) break;
        m -= i;
    }
    cout << m << endl;

    return 0;
}
