# include <stdio.h>
int n, m;
int main()
{
    while (scanf("%d%d", &n, &m) != EOF) {
        printf("%d\n", (m+n-1)%n);
    }
    return 0;
}
