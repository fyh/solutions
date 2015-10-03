# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

int v[maxn];
int f[maxn];

int dp(int x) {
    if (f[x] != -1) return f[x];
    if (!v[x] || x <= 2) return f[x] = 0;
    f[x] = 1;
    for (int i = 1; i <= v[x]; ++i) f[x] += dp(i);
}

void pre() {
    for (int i = 1; i*(i+1)/2<maxn; ++i) v[i*(i+1)/2] = i;
    memset(f, -1, sizeof(f));
    for (int i = 1; i < maxn; ++i) dp(i);
}

int main()
{
    pre();

    int k; cin >> k;
    if (f[k]%2 == 1) cout << v[k] << endl;
    else cout << -1 << endl;

    return 0;
}
