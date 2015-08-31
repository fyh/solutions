// editorial : http://codeforces.com/blog/entry/1620

# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;

int main()
{
    cin >> n;
    int h = n / 2;
    cout << h * (n-h) << endl;
    for (int i = 1; i <= h; ++i) {
        for (int j = h+1; j <= n; ++j) {
            cout << i << ' ' << j << endl;
        }
    }

    return 0;
}
