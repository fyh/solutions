# include <algorithm>
# include <stdio.h>

const int maxn = 1005;

int m, n;
int a[maxn];
int b[maxn];

int main()
{
    while (~scanf("%d%d", &m, &n)) {
        for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
        int ans = 0x3F3F3F3F;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = std::min(ans, std::abs(a[i]-b[j]));
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
