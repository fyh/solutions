# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;

int main()
{
    cin >> n;
    if (n <= 2) cout << -1 << endl;
    else {
        cout << 6 << endl;
        lli ba = 2;
        for (int i = 1; i < n-1; ++i) {
            cout << ba*5 << endl;
            ba *= 2;
        }
        cout << 15 << endl;
    }

    return 0;
}
