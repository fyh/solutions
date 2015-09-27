# include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (b == 0) cout << 1 << endl;
        else if (a > 4*b) {
            cout << (1.0 - (1.0*b)/a) << endl;
        } else {
            cout << 0.5+0.0625*a/b << endl;
        }
    }

    return 0;
}
