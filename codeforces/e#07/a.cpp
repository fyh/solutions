# include <bits/stdc++.h>

using namespace std;

# define testin freopen("in.txt", "r", stdin)

typedef long long int lli;

int main()
{
    lli n;
    cin >> n;
    lli k = sqrt(2.0*n);

    k = max(1, (int)k-5);

    while ((k+1)*k/2 < n) ++k;

    --k;

    cout << n - k*(k+1)/2 << endl;

    return 0;
}
