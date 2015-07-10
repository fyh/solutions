# include <stdio.h>
# include <string.h>
int n;
char s[2][5];
char b[105][105];
int main()
{
    bool first = true;
    while (~scanf("%d%s%s", &n, s[0], s[1])) {
        if (first) first = false;
        else puts("");

        if (n == 1) {
            puts(s[0]);
            continue;
        }

        memset(b, 0, sizeof(b));
        int t = ((n-1)/2) % 2;
        b[0][0] = b[0][n-1] = ' ';
        b[n-1][0] = b[n-1][n-1] = ' ';
        char ch = s[t][0];
        for (int i = 1; i < n-1; ++i) b[0][i] = ch;
        for (int i = 1; i < n-1; ++i) b[n-1][i] = ch;
        for (int i = 1; i < n-1; ++i) b[i][0] = ch;
        for (int i = 1; i < n-1; ++i) b[i][n-1] = ch;
        int lx = 1, ly = 1, rx = n-2, ry = n-2;
        t = 1 - t;
        while (lx<=rx && ly<=ry) {
            for (int i = lx; i <= rx; ++i) b[ly][i] = s[t][0];
            for (int i = ly+1; i <= ry; ++i) b[i][rx] = s[t][0];
            for (int i = lx; i < rx; ++i) b[ry][i] = s[t][0];
            for (int i = ly+1; i < ry; ++i) b[i][lx] = s[t][0];
            ++lx, ++ly, --rx, --ry;
            t = 1 - t;
        }
        for (int i = 0; i < n; ++i) puts(b[i]);
    }

    return 0;
}
/*
 @@@@@@@@@
@*********@
@*@@@@@@@*@
@*@*****@*@
@*@*@@@*@*@
@*@*@*@*@*@
@*@*@@@*@*@
@*@*****@*@
@*@@@@@@@*@
@*********@
 @@@@@@@@@
*/
