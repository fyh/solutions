# include <stdio.h>

char str[50005];

int main()
{
    while (~scanf("%s", str)) {
        for (int i = 0; str[i]; ++i) {
            if (i&&i%76==0) putchar('\n');
            putchar(str[i]);
        }
        putchar('\n');
        putchar('\n');
    }

    return 0;
}
