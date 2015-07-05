// BKDRHash
// https://www.byvoid.com/blog/string-hash-compare
# include <stdio.h>

const int maxn = 5e6+5;
char s[maxn];
int h[maxn];

const int M = 131;

int main()
{
    scanf("%s", s);
    int p = 0, q = 0, f = 1, ans = 0;
    for (int i = 0; s[i]; ++i) {
        p = p*M + s[i]; q = q + s[i]*f; f *= M;
        if (p == q) h[i+1] = h[(i+1)>>1] + 1;
        ans += h[i+1];
    }
    printf("%d\n", ans);

    return 0;
}
