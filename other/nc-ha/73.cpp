# include <stdio.h>
# include <ctype.h>

int main()
{
    char s[105];
    while (~scanf("%s", s)) {
        for (int i = 0; s[i]; ++i) {
            if (isalpha(s[i])) {
                if (i && s[i-1]=='_') {
                    putchar(toupper(s[i]));
                } else {
                    putchar(s[i]);
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
