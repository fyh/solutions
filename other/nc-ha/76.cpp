# include <stdio.h>
# include <algorithm>

int n;
int a[20005];
int q[20005];

int main()
{
    while (~scanf("%d", &n)) {
        if (!n) break;
        for (int i = 0; i < 2*n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < 2*n; ++i) {
            if (!i) q[i] = a[2*n-1];
            else q[i] = a[2*n-1-i] + q[i-1];
        }
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < 2*n; ++i) {
            sum += a[i];
            int x = std::lower_bound(q, q+2*n, sum) - q;
            int y = std::upper_bound(q, q+2*n, sum) - q;
            int k = y - x;
            int t = 2*n-1-i;
            if (x<=t&&t<y&&k) --k;
            ans += k;
        }
        printf("%d\n", ans);
    }
    return 0;
}
