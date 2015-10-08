# include <stdio.h>
# include <string.h>

const int maxn = 1e7+5;

char s[maxn];
int p;

int get(char *str) {
    int ret = 0;
    for (int i = 0; str[i]; ++i) {
        ret = ret*10 + str[i]-'0';
    }
    return ret;
}

int main()
{
    scanf("%s%d", s, &p);
    if (p == 1) puts("0");
    else {
        int j = 0;
        for (;s[j] == '0'; ++j) ;
        if (strlen(s+j) >= 7) puts("0");
        else {
            int x = get(s+j);
            if (x >= p) puts("0");
            else {
                long long int t = 1;
                for (int i = 1; i <= x; ++i) {
                    t *= i;
                    t %= p;
                }
                int ans = t;
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}

