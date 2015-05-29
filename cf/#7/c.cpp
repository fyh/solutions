# include <stdio.h>

typedef long long int lli;

int ext_gcd(lli a, lli b, lli &x, lli &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    lli c = ext_gcd(b, a%b, x, y);
    lli t = x;
    x = y;
    y = t - a/b * x;
    return c;
}

int A, B, C;

lli lb = -5000000000000000000LL, ub = 5000000000000000000LL;

int main()
{
    scanf("%d%d%d", &A, &B, &C);
    lli x, y;
    lli gg = ext_gcd(A, B, x, y);
    x *= -C/gg, y *= -C/gg;
    if (A%gg==0 && B%gg==0 && C%gg==0 && lb<=x&&x<=ub && lb<=y&&y<=ub) printf("%I64d %I64d\n", x, y);
    else printf("-1\n");

    return 0;
}
