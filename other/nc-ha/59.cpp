# include <stdio.h>

const int maxn = 100005;

char s[maxn];
char t[maxn];

int main()
{
    while (~scanf("%s%s", s, t)) {
        int i = 0, j = 0;
        for (; s[i]&&t[j];) {
            if (s[i] == t[j]) ++i, ++j;
            else ++i;
        }
        if (!t[j]) puts("Yes");
        else puts("No");
    }

    return 0;
}
