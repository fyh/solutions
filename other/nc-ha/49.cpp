# include <stdio.h>
# include <algorithm>

int n;
int a[1005];

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        std::sort(a, a+n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = std::max(ans, a[i]*(n-i));
        }
        printf("%d\n", ans);
    }
    return 0;
}
