# include <stdio.h>
# include <string.h>
# include <algorithm>

int n;
int a[105][105];

int main()
{
    while (~scanf("%d", &n)) {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = n-1; i >= 1; --i) {
            for (int j = 1; j <= n; ++j) {
                a[i][j] += std::max(a[i+1][j], a[i+1][j+1]);
            }
        }
        printf("%d\n", a[1][1]);
    }

    return 0;
}
