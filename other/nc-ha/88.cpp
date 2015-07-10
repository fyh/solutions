# include <stdio.h>
# include <algorithm>

int n, k;
int a[1055];

int main()
{
    while (~scanf("%d%d", &n, &k)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < k; ++i) {
            std::next_permutation(a, a+n);
        }
        for (int i = 0; i < n; ++i) {
            if (i) putchar(' ');
            printf("%d", a[i]);
        }
        putchar('\n');
    }

    return 0;
}
