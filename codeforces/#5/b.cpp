# include <stdio.h>
# include <string.h>
# include <algorithm>

const int maxl = 5005;
const int maxn = 1005;
char s[maxl][maxn];
int mx = 0;
void p(char ch, int n) {
    for (int i = 0; i < n; ++i) putchar(ch);
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int n = 0;
    while (gets(s[n]) != NULL) {
        mx = std::max(mx, (int)strlen(s[n]));
        ++n;
    }
    int c = 1;
    for (int i = -1; i <= mx; ++i) putchar('*'); putchar('\n');
    for (int i = 0; i < n; ++i) {
        putchar('*');
        int l = strlen(s[i]);
        int le, ri;
        le = (mx-l) / 2;
        ri = (mx-l) / 2;
        if (l%2 != mx%2){
            if (!c) ++le;
            else ++ri;
            c = 1 - c;
        }
        p(' ', le);
        printf("%s", s[i]);
        p(' ', ri);
        putchar('*');
        putchar('\n');
    }
    for (int i = -1; i <= mx; ++i) putchar('*'); putchar('\n');
    return 0;
}

