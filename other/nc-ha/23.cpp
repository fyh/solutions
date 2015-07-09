# include <stdio.h>
# include <string.h>
# include <algorithm>

int n;

int a[256];

int main()
{
    while (~scanf("%d", &n)) {
        memset(a, 0, sizeof(a));
        char s[5], t[15];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s%s", s, t);
            if (t[0] == 'd') {
                --a[ s[0] ];
            } else {
                ++a[ s[0] ];
            }
            int cur = 0;
            for (int j = 'A'; j <= 'Z'; ++j) cur += a[j];
            ans= std::max(ans, cur);
        }
        printf("%d\n", ans);
    }

    return 0;
}
