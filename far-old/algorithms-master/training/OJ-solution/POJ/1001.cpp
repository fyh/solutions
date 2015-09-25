// 18:16
# include <stdio.h>
# include <string.h>
# include <algorithm>

const int maxn = 205;
char a[maxn];

char s[10];
int R;

int trim(char *str)
{
    int ret = -1;
    for (int i = 0; str[i]; ++i) if (str[i]=='.') ret = 5-i;
    if (ret < 0) ret = 0;
    else for (int i = 5-ret; str[i]; ++i) str[i] = str[i+1];
    return ret;
}

int main()
{
    while (scanf("%s%d", s, &R) != EOF) {
        int n = trim(s);
        memset(a, 0, sizeof(a));
        int len = strlen(s);
        int b = 0;
        for (int i = 0; s[i]; ++i ) b = b*10 + s[i]-'0';
        a[0] = 1;
        for (int i = 0; i < R; ++i) {
            int c = 0;
            for (int j = 0; j < maxn; ++j) {
                int tmp = a[j]*b + c;
                a[j] = tmp%10;
                c = tmp/10;
            }
        }
        for (int i = 0; i < maxn; ++i) a[i] += '0';
        n = n * R;
        for (int i = maxn-1; i > n; --i) a[i] = a[i-1]; a[n] = '.';
        for (int i = 0; i < maxn/2; ++i) std::swap(a[i], a[maxn-1-i]);
        int i = 0, j = maxn-1;
        while (a[i]=='0') ++i;
        while (a[j]=='0') --j; if (a[j]=='.') --j;
        for (; i <= j; ++i) printf("%c", a[i]); printf("\n");
    }

    return 0;
}
