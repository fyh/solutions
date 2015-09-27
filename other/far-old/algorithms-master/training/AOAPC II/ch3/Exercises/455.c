# include <stdio.h>
# include <string.h>
int test(char *s, int p, int c)
{
    int i, j;
    for (i = 1; i < c; ++i) {
        for (j = 0; j < p; ++j) {
            if (s[i*p+j] != s[j]) return 0;
        }
    }
    return 1;
}
int main()
{
    int T, n, i;
    char s[86];

    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        n = strlen(s);
        for (i = 1; i <= n; ++i) {
            if (n%i==0 && test(s, i, n/i)) {
                break;
            }
        }
        printf("%d\n", i);
        if (T) printf("\n");
    }
    return 0;
}
