# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 2005;

int n, b;
int a[maxn];

int main()
{
    cin >> n >> b;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = b;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (a[i] < a[j]) {
                ans = max(ans, b/a[i]*a[j]+b%a[i]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
