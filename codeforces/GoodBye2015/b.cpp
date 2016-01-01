# include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

int main()
{
    ull a, b;
    cin >> a >> b;

    int ans = 0;
    ull o = 1;
    for (int i = 2; i < 64; ++i) {
        ull t = (o<<i) - 1;
        for (int j = 1; j < i; ++j) {
            ull t2 = t - (o<<(j-1));
            if (a<=t2&&t2<=b) {
                ++ ans;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
