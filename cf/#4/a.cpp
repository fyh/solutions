# include <stdio.h>

int w;
int main()
{
    scanf("%d", &w);
    if (w<=2) puts("NO");
    else puts(w%2==0 ? "YES":"NO");
    return 0;
}

