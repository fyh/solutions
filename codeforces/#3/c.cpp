# include <stdio.h>

int cx = 0, co = 0;
int w = 0;

char b[5][5];
void read(void)
{
    for (int i = 0; i < 3; ++i) scanf("%s", b[i]);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (b[i][j] == 'X') ++cx;
            else if (b[i][j] != '.') ++co;
        }
    }
}
int getCount(void)
{
    int cw = 0, rw = 0, dw = 0;
    int ret = 0;
    for (int i = 0; i < 3; ++i) {
        if (b[i][0]!='.' && b[i][0]==b[i][1] && b[i][1]==b[i][2]) {
            ++rw;
            ++ret ;
            w = (b[i][0] == 'X' ? 1:2);
        }
        if (b[0][i]!='.' && b[0][i]==b[1][i] && b[1][i]==b[2][i]) {
            ++cw;
            ++ret;
            w = (b[0][i] == 'X' ? 1:2);
        }
    }
    if (b[0][0]!='.'&&b[0][0]==b[1][1] && b[1][1]==b[2][2]) {
        ++dw;
        ++ret;
        w = (b[0][0] == 'X' ? 1:2);
    }
    if (b[1][1]!='.'&&b[2][0]==b[1][1] && b[0][2]==b[1][1]) {
        ++dw;
        ++ret;
        w = (b[1][1] == 'X' ? 1:2);
    }
    if (rw>1 || cw>1) ret = 2;
    else if (ret > 0) ret = 1;
    return ret;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    read();
    if (cx==co || cx==co+1) {
        int cnt = getCount();
        if (cnt != 0) {
            // check
            if (cnt != 1) puts("illegal");
            else {
                if (w==1 && cx!=co+1 || w==2 && cx!=co) puts("illegal");
                else puts(w==1 ? "the first player won":"the second player won");
            }
        } else {
            if (cx+co != 9) puts(cx==co ? "first":"second");
            else puts("draw");
        }
    } else {
        puts("illegal");
    }
    return 0;
}
