/*
1 2 3 3
2 2 2 1
1 1 4 3
*/
# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    lli M = 1e9+7;
    lli p3 = 1, p7 = 1;
    for (int i = 0; i < 3*n; ++i) {
        p3 = p3*3%M;
        if (i%3==0) p7 = p7*7%M;
    }

    cout << (p3-p7+M)%M << endl;

    return 0;
}

