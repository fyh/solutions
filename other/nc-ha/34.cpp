# include <stdio.h>
# include <string.h>
# include <algorithm>

const int maxn = 1055;

char s[maxn];
char t[maxn];

int f[maxn][maxn];

int main()
{
    while (~scanf("%s%s", s, t)) {
        memset(f, 0, sizeof(f));
        int n = strlen(s);
        int m = strlen(t);
        for (int i = 0; s[i]; ++i) {
            for (int j = 0; t[j]; ++j) {
                if (s[i]==t[j]) f[i+1][j+1] = f[i][j]+1;
                else f[i+1][j+1] = std::max(f[i][j+1], f[i+1][j]);
            }
        }

        printf("%d\n", f[n][m]);
    }
    return 0;
}
