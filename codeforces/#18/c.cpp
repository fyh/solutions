# include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;

int n;
int a[maxn];

int p[maxn];
int q[maxn];

int main()
{
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        p[0] = q[n+1] = 0;
        for (int i = 1; i <= n; ++i) {
            p[i] = a[i] + p[i-1];
            int t = n - i + 1;
            q[t] = a[t] + q[t + 1];
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (p[i] == q[i+1]) ++ans;
        }
        cout << ans << endl;
    }

    return 0;
}
