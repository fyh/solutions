# include <stdio.h>

int y, m, d;

int md[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    while (~scanf("%d-%d-%d", &y, &m, &d)) {
        int ans = 0;
        for(int i = 0; i < m; ++i) ans += md[i];
        ans += d;
        if ((y%4==0&&y%100!=0) || y%400==0) {
            if (m > 2) ++ans;
        }
        printf("%d\n", ans);
    }

    return 0;
}
