# include <stdio.h>
# include <string.h>
# include <algorithm>

const int maxn = 1055;

char s[maxn];
char t[maxn];
int f[maxn][maxn];

int main()
{
    while (~scanf("%s%s", s,t)) {
        int n = strlen(s);
        int m = strlen(t);
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) f[i+1][0] = i+1;
        for (int i = 0; i < m; ++i) f[0][i+1] = i+1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                /*
                int x = (s[i]==t[j] ? 0:1);
                f[i+1][j+1] = std::min(f[i][j]+x, 1+std::min(f[i][j+1],f[i+1][j]));
                */
                if (s[i] == t[j]) f[i+1][j+1] = f[i][j];
                else f[i+1][j+1] = std::min(f[i][j], std::min(f[i+1][j], f[i][j+1]))+1;
            }
        }
        printf("%d\n", f[n][m]);
    }

    return 0;
}
