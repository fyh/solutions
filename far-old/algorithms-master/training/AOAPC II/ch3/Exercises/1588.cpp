# include <cstdio>
# include <cstring>
int Max(int x, int y) {return x>y?x:y;}
const int maxn = 105;
char s[maxn], t[maxn];
int match(char *ss, char *st)
{
    int ret = 0;
    for (int i = 0; ss[i]; ++i) {
        int j = 0;
        while (ss[i+j]&&st[j]&&(ss[i+j]+st[j]-'0'<'4')) ++j;
        if (!ss[i+j]||!st[j]) ret = Max(ret, j);
    }
    return ret;
}
int main()
{
    while (scanf("%s%s", s, t)!=EOF) {
        printf("%d\n",strlen(s)+strlen(t)-Max(match(s, t),match(t,s)));
    }

    return 0;
}
