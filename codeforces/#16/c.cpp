# include <bits/stdc++.h>

int a, b, x, y;

int gcd(int aa, int bb) { return !bb ? aa:gcd(bb,aa%bb); }

int main()
{
    scanf("%d%d%d%d", &a, &b, &x, &y);

    int t = gcd(x, y);
    x /= t;
    y /= t;

    t = std::min(a/x, b/y);

    if (t <= 0) printf("0 0\n");
    else printf("%d %d\n", x*t, y*t);

    return 0;
}
