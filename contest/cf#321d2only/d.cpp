# include <bits/stdc++.h>
# define speedup cin.tie(0);ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int lli;

const int maxn = 17+2;

int n, m, k;
lli a[maxn];
lli c[maxn][maxn];
lli f[0x1<<maxn][maxn];
lli ans;

lli dp(int s, int t) {
    if (f[s][t] != -1) return f[s][t];
    if (s == 0) return f[s][t] = 0;
    if (!(s&(0x1<<t))) return f[s][t] = 0;

    if (s == (0x1<<t)) {
        if (m == 1) ans = max(ans, a[t]);
        return f[s][t] = a[t];
    }

    f[s][t] = a[t];
    int cb = 0;
    for (int i = 0; i < n; ++i) if ((s>>i)&0x1) if (i != t) {
        ++cb;
        f[s][t] = max(f[s][t], a[t]+dp(s-(0x1<<t), i)+c[i][t]);
    }
    if (cb+1 == m) ans = max(ans, f[s][t]);
    return f[s][t];
}

void init() {
    speedup;

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) {
        int u, v, w; cin >> u >> v >> w;
        c[u-1][v-1] = w;
    }
    memset(f, -1, sizeof(f));
}

void solve() {
    for (int i = 0; i < n; ++i) dp((0x1<<n)-1, i);
    cout << ans << endl;
}

int main()
{
    init();
    solve();

    return 0;
}
