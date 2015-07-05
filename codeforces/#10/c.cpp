# include <bits/stdc++.h>

typedef long long int lli;

lli ans;

const int maxn = 1e6+5;
lli d[maxn];

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) ++d[i%9], ans -= n/i;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            ans += d[i]*d[j]*d[(i*j)%9];
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
