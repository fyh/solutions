# include <stdio.h>
# include <algorithm>
char s[10][10];
int main()
{
    for (int i = 0; i < 8; ++i) scanf("%s", s[i]);
    int ans = 0;
    int cr = 0, cc = 0;
    for (int i = 0; i < 8; ++i) {
        bool ok1 = true, ok2 = true;
        for (int j = 0; j < 8; ++j) {
            if (s[i][j] != 'B') ok1 = false;
            if (s[j][i] != 'B') ok2 = false;
        }
        if (ok1) ++cr;
        if (ok2) ++cc;
    }
    if (cc>=8 || cr>=8) ans = 8;
    else ans = cc + cr;
    printf("%d\n", ans);
}