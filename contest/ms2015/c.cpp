# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e6+5;
const int maxa = 1e5+5;
const int maxd = 30;
const lli MOD = 1000000007;

int fib[maxn];
map<int,int> fc;
void pre() {
    fib[1] = fib[2] = 1;
    for (int i = 3; i < maxn; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
        if (fib[i] >= maxa) {
            break;
        }
        fc[ fib[i] ] = i;
    }
}

lli f[maxn][maxd];

int n;
int a[maxn];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    pre();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) memset(f[i], 0, sizeof(f[i]));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < maxd; ++j) f[i][j] = f[i-1][j];
        if (a[i] == 1) {
            f[i][1] = (f[i][1] + 1) % MOD;
            f[i][2] = (f[i][2] + f[i-1][1]) % MOD;
        } else if (fc.count(a[i])) {
            int t = fc[ a[i] ];
            f[i][t] = (f[i][t]+f[i-1][t-1]) % MOD;
        }
    }

    lli ans = 0;
    for (int i = 1; i < maxd; ++i) {
        ans = (ans + f[n][i]) % MOD;
    }
    cout << ans << endl;

    return 0;
}
