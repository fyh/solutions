# include <bits/stdc++.h>

# define testin freopen("in.txt", "r", stdin)

int n, x0;
int c[1005];

int main()
{
   // testin;
    scanf("%d%d", &n, &x0);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y) std::swap(x, y);
        for (int j = x; j <= y; ++j) {
            ++c[j];
        }
    }
    int ans = 1005;
    bool ex = false;
    for (int i = 0; i < 1005; ++i) {
        if (c[i] == n) {
            ex = true;
            ans = std::min(ans, std::abs(i-x0));
        }
    }
    if (!ex) ans = -1;
    printf("%d\n", ans);

    return 0;
}
