# include <string.h>
# include <stdio.h>

const int maxn = 1005;

int a[maxn];
char s[maxn];
int b[maxn];
bool e[maxn];
int t[maxn][maxn];

void doit(int n) {
    for (int i = 1; i <= n; ++i) a[i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (j%i) {
                b[j] = a[j];
            } else {
                int inc = (i&0x1) ? -1:1;
                int next = (j/i+inc)*i;
                if (next > n) next = i;
                if (next <= 0) next = n/i*i;
                b[j] = a[next];
            }
        }
        for (int j = i ; j <= n; ++j) {
            a[j] = b[j];
        }
    }
    for (int i = 1; i <= n; ++i) t[n][a[i]] = i;
    e[n] = true;
}

int main()
{
    while (gets(s+1) != NULL) {
        int n = strlen(s+1);
        if (!e[n]) doit(n);
        for (int i = 1; i <= n; ++i) putchar( s[ t[n][i] ] );
        putchar('\n');
    }
    return 0;
}
