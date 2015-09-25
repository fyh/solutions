# include <stdio.h>
# include <string.h>
const int maxn = 55;
const int maxm = 105;
int n,m;

char s[maxm][maxn];
int a[maxm];
int r[maxm];

int c[maxn*maxn];

int getCal(char *str) {
    int cnt[256];
    int ret = 0;
    cnt['A'] = cnt['C'] = cnt['G'] = cnt['T'] = 0;
    for (int i = 0; str[i]; ++i) {
        ++cnt[ str[i] ];
        switch( str[i] ) {
        case 'A': ret += cnt['C']+cnt['G']+cnt['T']; break;
        case 'C': ret += cnt['G']+cnt['T'];break;
        case 'G': ret += cnt['T'];break;
        }
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(c, 0, sizeof(c[0])*(n*n));
    for (int i = 0; i < m; ++i) {
        scanf("%s", s[i]);
        a[i] = getCal(s[i]);
        ++c[ a[i] ];
    }

    for (int i = 1; i < n*n; ++i)  c[i] += c[i-1];
    for (int i = m-1; i >= 0; --i) {
        r[ --c[ a[i] ] ] = i;
    }
    for (int i = 0; i < m; ++i) {
        printf("%s\n", s[ r[i] ]);
    }

    return 0;
}
