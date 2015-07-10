# include <stdio.h>
# include <string.h>

char s[105];

bool jd(int x, int n) {
    for (int i = 0; i < n; ++i) {
        if (s[x+i] != s[x+n-1-i]) return false;
    }
    for (int i = 0; i < n; ++i) putchar(s[x+i]); putchar('\n');
    return true;
}

int main()
{
    while (~scanf("%s", s)) {
        int n = strlen(s);
        bool ok = true;
        for (int t = n; ok&&t >= 0; --t) {
            for(int i = 0; ok&&i < n; ++i) {
                if (i+t > n) continue;
                if (jd(i, t)) {
                    ok = false;
                    break;
                }
            }
        }
    }

    return 0;
}
