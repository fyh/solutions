# include <stdio.h>
# include <string.h>

char *a = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char ch;
    int n = strlen(a);
    while ( (ch = getchar()) != EOF ) {
        if ( ch == ' ' ) putchar(ch);
        else {
            char find = 0;
            for (int i = 0; i < n; ++i) {
                if (ch == a[i]) {
                    putchar(a[i-1]);
                    find = 1;
                    break;
                }
            }
            if (!find) putchar(ch);
        }
    }

    return 0;
}
