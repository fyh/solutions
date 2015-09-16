# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n, k;
int a[105];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; ++a[x];
    }
    int ans = 0;
    while (a[k] < n) {
        for (int j = k-1; j >= 1; --j) {
            if (a[j]) {
                --a[j];
                ++a[j+1];
            }
        }
        ++ans;
    }
    cout << ans << endl;

    return 0;
}
