# include <stdio.h>
# include <string.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char ch;
    int i = 0;
    while ( (ch = getchar()) != EOF )  {
        if ( ch == '\"' ) {
            if ( i%2 ) {
                printf("''");
            } else {
                printf("``");
            }
            ++i;
        } else {
            putchar(ch);
        }
    }

    return 0;
}
