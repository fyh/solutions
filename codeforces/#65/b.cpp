# include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, t;
    cin >> n >> k >> t;

    int sum = n*k*t/100;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (cur + k <= sum) {
            cur += k;
            cout << k << ' ';
        } else {
            cout << sum - cur << ' ';
            ++i;
            while (i < n) {
                ++i;
                cout << 0 << ' ';
            }
            return 0;
        }
    }

    return 0;
}
