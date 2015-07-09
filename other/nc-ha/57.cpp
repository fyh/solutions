# include <stdio.h>

int n;
int a[55];

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        double s = 10000.0;
        for (int i = 1; i < n; ++i) {
            if (a[i]>a[i-1]) s = s * a[i] / a[i-1];
        }
        printf("%.2lf\n", s);
    }
    return 0;
}
