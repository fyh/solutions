# include <stdio.h>
# include <algorithm>

double a[15];

int main()
{
    while (~scanf("%lf", &a[0])) {
        for (int i = 1; i < 9; ++i) scanf("%lf", &a[i]);
        double ans = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = i+1; j < 9; ++j) {
                ans = std::max(ans, a[j]-a[i]);//printf("%.2lf\n", a[j]-a[i]);
            }
        }
        printf("%.2lf\n", ans);
    }

    return 0;
}
