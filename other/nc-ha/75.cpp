# include <stdio.h>
# include <string.h>

char b[15][15];
char a[15][15];
int n;
char s[15];
char t[15];

bool jd() {
    for (int i = 0; i < 10; ++i) {
        if (strstr(b[i], s) != NULL) return true;
        if (strstr(a[i], s) != NULL) return true;
        if (strstr(b[i], t) != NULL) return true;
        if (strstr(a[i], t) != NULL) return true;
    }
    return false;
}

int main()
{
   // freopen("in.txt", "r", stdin);
    while (~scanf("%s", b[0])) {
        for (int i = 1; i < 10; ++i) scanf("%s", b[i]);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                a[i][j] = b[j][i];
            }
        }
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            memset(t, 0, sizeof(t));
            int m = strlen(s);
            for (int j = 0; s[j]; ++j) t[j] = s[m-1-j];
            if (jd()) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }

    return 0;
}
