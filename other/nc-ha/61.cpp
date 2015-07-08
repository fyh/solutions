# include <string.h>
# include <stdio.h>

int main()
{
  //  freopen("in.txt", "r", stdin);
  //  freopen("out2.txt", "w", stdout);
    int ch;
    while (EOF!=(ch=getchar())) {
        switch(ch) {
        case '<':
            printf("&lt;");
            break;
        case '>':
            printf("&gt;");
            break;
        case ' ':
            printf("&nbsp;");
            break;
        case '\t':
            printf("&#9;");
            break;
        default:
            putchar(ch);
            break;
        }
    }

    return 0;
}
