# include <string.h>
# include <stdio.h>

int n;
char s[205][205];
bool spc[205];

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 0; i <= n; ++i) gets(s[i]);
        memset(spc, false, sizeof(spc));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; s[i][j]; ++j) {
                if (s[i][j] == ' ' || s[i][j] == ',') {
                    spc[i] = true;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (i>1) printf(", ");
            if (spc[i]) printf("\"");
            printf("%s", s[i]);
            if (spc[i]) printf("\"");
        }
        printf("\n");
    }
    return 0;
}
