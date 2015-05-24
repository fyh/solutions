# include <algorithm>
# include <stdio.h>
int main()
{
    char s[3], g[3];
    scanf("%s%s", s, g);
    int x = s[0]-g[0];
    int y = s[1]-g[1];
    char cx = x<0 ? x=-x,'R':'L';
    char cy = y<0 ? y=-y,'U':'D';
    printf("%d\n", std::max(x,y));
    while (x||y) {
        if (x) putchar(cx), --x;
        if (y) putchar(cy), --y;
        puts("");
    }
    return 0;
}
