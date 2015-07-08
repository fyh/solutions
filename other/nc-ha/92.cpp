# include <string.h>
# include <stdio.h>

const int maxn = 155;

int n, k;

int a[maxn];
char s[maxn];
char t[maxn];

void doit() {
    for (int i = 1; i <= n; ++i) {
        t[ a[i] ] = s[i];
    }
    for (int i = 1; i <= n; ++i) {
        s[i] = t[i];
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    while ((~scanf("%d%d", &n, &k)) && n && k) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        scanf("%s", s+1);
        int len = strlen(s+1);
        for (int i = len+1; i <= n; ++i) s[i] = ' '; s[n+1] = 0;
        for (int i = 0; i < k; ++i) {
            doit();
        }
        puts(s+1);
    }

    return 0;
}
