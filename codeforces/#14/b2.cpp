# include <bits/stdc++.h>

int n, x0;

int main()
{
    int L = -1, R = 1005;

    scanf("%d%d", &n, &x0);
    for (int i = 0, x, y; i < n; ++i) {
        scanf("%d%d", &x, &y);
        if (x > y) std::swap(x, y);
        L = std::max(L, x);
        R = std::min(R, y);
    }

    if (L > R) puts("-1");
    else if (L<=x0 && x0<=R) puts("0\n");
    else printf("%d\n", std::min(std::abs(L-x0), std::abs(R-x0)));

    return 0;
}
