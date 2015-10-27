# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 5e5+5;

int n;
int a[maxn];
int b[maxn];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = a[1], a[n+1] = a[n];
    for (int i = 1; i <= n; ++i) {
        if (a[i]==a[i-1] || a[i]==a[i+1]) b[i] = 1;
    }
    int p = 1;
    int ans = 0;
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        if (b[i]) {
            if (ok) ++p;
            else {
                ans = max(ans, (i-p)/2);
                //
            }
            ok = true;
        } else {
            ok = false;
        }
    }

    return 0;
}
