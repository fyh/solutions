# include <stdio.h>
const int maxn = 1005;
const int maxk = 105;
char ch[maxk];
int side[maxn][maxk];
char op[maxn][maxk];
int first[maxn];
char getChar(int k, int side)
{
    return side<0 ? ch[k]:('>'+'<'-ch[k]);
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i) {
        int t; scanf("%d", &t);
        for (int j = 0; j < 2*t; ++j) {
            int x; scanf("%d", &x);
            side[x][i] = j<t ? -1:1;
        }
        char s[5]; scanf("%s", s);
        ch[i] = s[0];
        if (ch[i]!='=') {
            for (int j = 1; j <= n; ++j) if (side[j][i]!=0) {
                op[j][i] = (side[j][i]<0 ? ch[i]:('>'+'<'-ch[i]));
                if (!first[j]) first[j] = i;
            }
        }
    }

    int sol, cnt  = 0;
    for (int i = 1; i <= n; ++i) {
        bool ok = true;
        for (int j = 1; j <= k; ++j) {
            if (!side[i][j]) {
                if (ch[j] != '=' ) ok = false;
            } else if(ch[j] == '=' || op[i][ first[i] ] != getChar(j, side[i][j])) {
                ok = false;
            }
            if (!ok) break;
        }
        if (ok) sol = i, ++cnt;
    }
    if (cnt != 1) printf("0\n");
    else printf("%d\n", sol);

    return 0;
}
