# include <stdio.h>
# include <cmath>
# include <algorithm>

char s[5], g[5];

int main()
{
    while (~scanf("%s%s", s, g)) {
        int sx = s[0]-'a'+1, sy = s[1]-'0';
        int gx = g[0]-'a'+1, gy = g[1]-'0';
        if (sx == gx && sy == gy) {
            puts("0 0 0 0");
            continue;
        }
        int a = std::max(std::abs(sx-gx), std::abs(sy-gy));
        int b, c, d;

        if (sx==gx || sy==gy || std::abs(sx-gx)==std::abs(sy-gy))  b = 1;
        else b = 2;

        if (sx==gx || sy==gy) {
            c = 1;
        } else {
            c = 2;
        }

        if (std::abs(sx-gx)==std::abs(sy-gy)) {
            d = 1;
        } else {
            if ((sx+sy)%2 != (gx+gy)%2) d = -1;
            else d = 2;
        }
        printf("%d %d %d ", a, b, c);
        if (d < 0) puts("Inf");
        else printf("%d\n", d);
    }

    return 0;
}
