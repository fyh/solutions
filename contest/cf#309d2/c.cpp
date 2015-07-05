# include <bits/stdc++.h>

# define testin freopen("in.txt", "r", stdin)

typedef long long int lli;

const int maxn = 1005;
const lli MOD = 1000000007;

int n;
int c[maxn];
lli s[maxn];
lli inv[maxn];

void pre(int m, int p){
    for (int i = 1; i < m; ++i) {
        inv[i] = (i==1 ? 1:(p+(-p/i)*inv[p%i]%p));
    }
}

lli Cs(int m, int n) {
    lli ret = 1;
    for (int i = 0; i < n; ++i) {
        ret = ( (ret % MOD) * (m+i) % MOD) * inv[i+1] % MOD;
    }
    return ret % MOD;
}

int main()
{
    // testin;

    scanf("%d", &n);

    pre(maxn, MOD);

    for (int i = 0; i < n; ++i) {scanf("%d", &c[i]); s[i] = c[i] + (!i ? 0:s[i-1]);}

    lli ans = 1;
    for (int i = 0; i < n; ++i) {
        int k = (!i ? 0:s[i-1]);
        ans = ans * Cs(k+1, c[i]-1) % MOD;
    }

    std::cout << (MOD + ans) % MOD << std::endl;

    return 0;
}
