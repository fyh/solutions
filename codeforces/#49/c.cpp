# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;

int main()
{
    cin >> n;
    int x = 1, y = n, cnt = 0;
    while (cnt < n) {
        if (cnt%2==0) cout << x++ << ' ';
        else cout << y-- << ' ';
        ++cnt;
    }
    cout << endl;

    return 0;
}
