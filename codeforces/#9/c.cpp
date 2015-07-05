# include <bits/stdc++.h>

typedef long long int lli;

lli n;

lli p10[15];

lli get(int x) {
    lli ret = 0;
    for (int i = 0; i < 11; ++i) {
        if ((x>>i)&0x1) ret += p10[i];
    }
    return ret;
}

int main()
{
    std::cin >> n;

    p10[0] = 1;
    for (int i = 1; i < 15; ++i) p10[i] = 10 * p10[i-1];

    int ans = 0;
    for (int i = 1; get(i) <= n; ++i, ++ans);
    std::cout << ans << std::endl;

    return 0;
}
