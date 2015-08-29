# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

int n;
int h[maxn];
int l[maxn];
int r[maxn];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 1; i <= n; ++i) {
        l[i] = min(l[i-1]+1, h[i]);
    }
    for (int i = n; i >= 1; --i) {
        r[i] = min(r[i+1]+1, h[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, min(l[i],r[i]));
    }
    cout << ans << endl;

    return 0;
}
