# include <stdio.h>
# include <string.h>
# include <ctype.h>

char A[] = "ECFAJKLBDGHIVWZYMNOPQRSTUX";
char a[] = "erwqtyghbnuiopsjkdlfazxcvm";

char s[50005];
int main()
{
    while (gets(s) != NULL) {
        if (s[0] == '#') break;
        for(int i = 0; s[i]; ++i) {
            if (isupper(s[i])) {
                s[i] = A[ s[i]-'A' ];
            } else if (islower(s[i])) {
                s[i] = a[ s[i]-'a' ];
            }
        }
        puts(s);
    }

    return 0;
}
