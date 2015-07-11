# include <stdio.h>
# include <algorithm>

int n = 24;
int a[55];
int r[55];

bool cmp(const int &x, const int &y) {
    if (std::abs(a[x]) == std::abs(a[y])) return x < y;
    return std::abs(a[x]) > std::abs(a[y]);
}

int main()
{
    while (~scanf("%d", &a[0])) {
        for (int i = 1; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) r[i] = i;
        std::sort(r, r+n, cmp);
        for (int i = 0; i < n; ++i) {
            if (i) putchar(' ');
            printf("%d", r[i]);
        }
        putchar('\n');
    }

    return 0;
}
