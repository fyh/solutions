# include <stdio.h>
# include <string.h>

int n, s;
char b[55][55*15];

int a[10][7] = {
    1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 0, 0, 0, 0,
    1, 1, 0, 1, 1, 0, 1,
    1, 1, 1, 1, 0, 0, 1,
    0, 1, 1, 0, 0, 1, 1,
    1, 0, 1, 1, 0, 1, 1,
    1, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 0, 1, 1
};

void print(int d, int x) {
    for (int i = 0; i < s; ++i) {
        // 0
        if (a[d][0]) b[0][i+x+1] = '-';
        // 6
        if (a[d][6]) b[s+1][i+x+1] = '-';
        // 3
        if (a[d][3]) b[2*s+2][i+x+1] = '-';
    }
    for (int i = 0; i < s; ++i) {
        // 1
        if (a[d][1]) b[i+1][x+s+1] = '|';
        // 2
        if (a[d][2]) b[i+s+2][x+s+1] = '|';
        // 5
        if (a[d][5]) b[i+1][x] = '|';
        // 4
        if (a[d][4]) b[i+s+2][x] = '|';
    }
}
int main()
{
    while (~scanf("%d%d", &s, &n)) {
        memset(b, 0, sizeof(b));
        int c = s + 2;
        int d = 0;
        int xn = n;
        while (xn > 0) {
            xn /= 10;
            ++d;
        }
        int nd = d;
        while (n > 0) {
            int t = n % 10;
            print(t, c*(d-1));
            --d;
            n /= 10;
        }
        for (int i = 0; i < 2*s + 3; ++i) {
            for (int j = 0; j < nd*(s+2); ++j) {
                if (j&&j%(s+2)==0) putchar(' ');
                if (!b[i][j]) putchar(' ');
                else putchar(b[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
    }

    return 0;
}
