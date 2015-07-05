# include <stdio.h>
const int maxn = 1e6+5;
char s[maxn];
int st[maxn], top = 0;
int b = -1;
int main()
{
    int ml = 0, mc;
    scanf("%s", s);
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(') {
            st[top++] = i;
        } else if (top > 0) {
            --top;
            int tl = (top > 0 ? i-st[top-1]:i-b);
            if (ml < tl) {ml = tl; mc = 1;}
            else if (ml == tl) ++mc;
        } else {
            b = i;
        }
    }
    printf("%d %d\n", ml, !ml?1:mc);

    return 0;
}
