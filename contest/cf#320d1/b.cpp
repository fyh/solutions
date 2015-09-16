# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 2e5+5;

int n, k, x;
int a[N];
lli b[N];
int p[N];
int q[N];

int main()
{
    cin >> n >> k >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        for (int j = 0; j < k; ++j) b[i] *= x;
    }

    p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i-1] | a[i];
    }

    q[n+1] = 0;
    for (int i = n; i >= 1; --i) {
        q[i] = q[i+1] | a[i];
    }

    lli ans = 0;
    for (int i = 1; i <= n; ++i) {
        lli cur = p[i-1] | b[i] | q[i+1];
        if (cur > ans) ans = cur;
    }
    cout << ans << endl;

    return 0;
}
