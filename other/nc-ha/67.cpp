# include <stdio.h>
# include <string.h>

char s[1055], t[55];

int main()
{
    freopen("in.txt", "r", stdin);
    while (gets(s) != NULL) {
        gets(t);
        char *p = s;
        int n = strlen(t);
        bool ok = true;
        while (true) {
            p = strstr(p, t);
            if(!p) break;
            if (p == s) {
                if (*(p+n)==',') {
                    ok = false;
                    break;
                }
            } else {
                if ((*(p-1)=='\"' && *(p+n)=='\"') ) {
                    ok = false;
                    break;
                }
                if ((*(p-1)==',' && *(p+n)==',')) {
                    int c = 0;
                    for (char *x = s; x != p; ++x) {
                        if (*x == '\"') ++c;
                    }
                    if (c%2 == 0) {
                        ok = false;
                        break;
                    }
                }
            }
            p = p + n;
        }
        puts(!ok ? "Ignore":"Important!");
    }

    return 0;
}
