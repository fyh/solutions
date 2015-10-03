# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 105;
const int INF = 305;

int n, T;
int a[maxn];
int b[maxn*maxn];
int c[maxn];
int f[maxn*maxn];

int get(int m)
{
    int ret = 0;
    for (int i = 0; i <= m; ++i) f[i] = INF;
    for (int i = 0; i < m; ++i) {
        int k = upper_bound(f, f+m, b[i]) - f;
        f[k] = b[i];
        ret = max(ret, k+1);
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> T;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i*n + j] = a[j];
        }
    }

    if (T <= n) {
        cout << get(T*n) << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        c[i] = get(i*n);
    }

    int d = c[n] - c[n-1];
    cout << c[n] + (T-n)*d << endl;

    return 0;
}
