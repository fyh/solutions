# include <queue>
# include <algorithm>
# include <stdio.h>
# include <math.h>

const int maxn = 15;
int n, a, b;
int h[maxn];
int q[maxn];

int ans = 0;

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; ++i) scanf("%d", &h[i]);

    for (int i = 1; i < n-1; ++i) {
        if (h[i-1] < 0 && i+1<n-1) continue;
        int t = (int)ceil((h[i-1]+1.0)/b);
        if (i+1==n-1) t = std::max(t, std::max((int)ceil((h[i]+1.0)/a), (int)ceil((h[i+1]+1.0)/b)));
        h[i-1] -= t*b;
        h[i] -= t * a;
        h[i+1] -= t*b;
        ans += t;
        q[i] = t;
    }
    printf("%d\n", ans);
    for (int i = 1; i < n-1; ++i) {
        for (int j = 0; j < q[i]; ++j) {
            printf("%d ", i+1);
        }
    }

    return 0;
}

