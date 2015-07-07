# include <iostream>
# include <cstdio>

typedef long long int lli;

lli gcd(lli a, lli b) {
    return !b ? a:gcd(b, a%b);
}

lli lcm(lli a, lli b) {
    return a / gcd(a,b) * b;
}

int m, n;
int a[15];
int b[15];

int solve()
{
    lli sn = 0, sd = 1;

    std::cin >> m >> n;
    if (!m && !n) return 0;
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) {
        sn = sn*a[i] + sd, sd = sd*a[i];
        lli t = gcd(sn, sd);
        sn /= t;
        sd /= t;
    }
    if ((m * sd) % sn != 0) return -1;
    lli num = m * sd / sn;
    for (int i = 0; i < n; ++i) {
        if (num%a[i] != 0) return -1;
        b[i] = num / a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i) std::cout << ' ';
        std::cout << b[i];
    }
    std::cout << std::endl;

    return 1;
}

int main()
{
 //   freopen("in.txt", "r", stdin);
    for (;;) {
        int r = solve();
        if (!r) break;
        else if (r == -1) std::cout << "Can't Solve" << std::endl;
    }
    return 0;
}
