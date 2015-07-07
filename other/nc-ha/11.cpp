# include <stdio.h>

char s[10005];

int main()
{
    while (~scanf("%s", s)) {
        int r = 0;
        for (int i = 0; s[i]; ++i) r = (r+s[i]-'0'+8)%9+1;
        printf("%d\n", r);
    }

    return 0;
}
