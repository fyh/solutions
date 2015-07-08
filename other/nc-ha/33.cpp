# include <stdio.h>
# include <algorithm>

int n;

int a[10005];
int f[10005];

const int INF = 9876543210;

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) {
            f[i] = INF;
            int k = std::lower_bound(f, f+i, a[i]) - f;
            f[k] = a[i];
        }
        printf("%d\n", std::lower_bound(f, f+n, INF)-f);
    }

    return 0;
}
