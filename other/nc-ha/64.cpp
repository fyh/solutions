# include <string.h>
# include <stdio.h>

char s[1055], t[1055];

int main()
{
    while (~scanf("%s%s", s, t)) {
        int ret = 0;
        char *p = s;
        int m = strlen(t);
        while (true) {
            p = strstr(p, t);
            if (!p) break;
            p = p + m;
            ++ret;
        }
        printf("%d\n", ret);
    }

    return 0;
}
