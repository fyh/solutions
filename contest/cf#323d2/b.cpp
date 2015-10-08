# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1005;

int n;
int a[maxn];
bool v[maxn];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int ans = 0;
    int cnt = 0;
    int d = 1, s = 1;
    while (cnt < n) {
        for (int i = 1; i <= n; ++i) {
            if (!v[i] && a[i]<=cnt) {
                v[i] = true;
                ++cnt;
            }
        }
        if (cnt < n) ++ans;
        for (int i = n; i >= 1; --i) {
            if (!v[i] && a[i]<=cnt) {
                v[i] = true;
                ++cnt;
            }
        }
        if (cnt < n) ++ans;
    }

    cout << ans << endl;

    return 0;
}
