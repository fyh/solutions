# include <stdio.h>
# include <algorithm>

int m, n;
int a[1005], b[1005];

int main()
{
    while (~scanf("%d%d", &m, &n)) {
        for (int i = 0; i < m; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }
        std::sort(a, a+m);
        std::sort(b, b+n);
        int ans = 0;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (a[i]==b[j]) ++i, ++j, ++ans;
            else if (a[i] < b[j]) ++i;
            else ++j;
        }
        printf("%d\n", ans);
    }
    return 0;
}
