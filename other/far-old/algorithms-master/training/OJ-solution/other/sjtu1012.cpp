# include <stdio.h>
# include <string.h>
# include <algorithm>

const int maxn = 200005;

int s, t;
int f[maxn];

int main()
{
    int ans1 = 0, ans2 = 0;
    scanf("%d%d", &s, &t);
    memset(f, 0, sizeof(f));
    for (int i = t; i <= t; ++i) {
        for (int j = 1; j < 1001; ++j) {
            int tmp = i*100/j;
            if (tmp*j == i*100) {
                f[tmp] = std::max(f[tmp], f[i]+1);
                if (f[tmp] > ans1) {
                    ans1 = f[tmp];
                    ans2 = 0;
                }
                if (f[tmp] == ans1) ++ans2;
            }
        }
    }
    printf("%d\n%d\n", ans1+1, ans2);

    return 0;
}
