# include <stdio.h>
# include <math.h>
# include <algorithm>

int a[7];

int main()
{
    while (~scanf("%d", &a[1])) {
        for (int i = 2; i <= 6; ++i) scanf("%d", &a[i]);
        double ans = a[6] + a[5] + a[4] + (int)ceil(a[3]/4.0);
        int t3 = 4 - (a[3] % 4); t3 = t3 % 4;
        int left = a[5] * 11 + a[4] * 20 + t3 * 9;
        int c2 = std::min(a[2], a[4]*5 + (t3?(t3*2-1):0));
        a[2] -= c2;
        left -= c2*4;
        if (a[2] > 0) {
            ans += (int)ceil(a[2]/9.0);
            int t2 = 9-a[2]%9; t2 = t2 % 9;
            left += t2*4;
        }
        a[1] = std::max(0, a[1]-left);
        ans += (int)ceil(a[1]/36.0);
        printf("%.0lf\n", ans);
    }

    return 0;
}
