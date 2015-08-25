# include <bits/stdc++.h>
using namespace std;

int a[8];

int s[][4] = {
    0, 2, 5, 7,
    1, 3, 4, 6
};

int t[][3] = {
    2, 0, 1,
    5, 0, 4,
    7, 0, 4,
    3, 1, 2,
    4, 1, 0,
    6, 1, 5,
    0, 0, 0,
};

void ch(int x, int y, int v) {
    a[x] += v, a[y] += v;
    for (int i = 0; i < abs(v); ++i) {
        printf("%c%c%c\n", x+'A', y+'A', v>0?'+':'-');
    }
}

void mov(int x, int y, int z, int v) {
    ch(x, y, v);
    ch(y, z, -v);
}

int main()
{
    for (int i = 0; i < 8; ++i) cin >> a[i];

    int c[2];
    for (int i = 0; i < 2; ++i) {
        c[i] = 0;
        for (int j = 0; j < 4; ++j) {
            c[i] += a[ s[i][j] ];
        }
    }

    if (c[0] != c[1]) {
        puts("IMPOSSIBLE");
        return 0;
    }

    for (int i = 0; i < 4; ++i) {
        int y = s[1][i], x = s[0][i];
        if (a[x] && a[y]) {
            ch(x, y, -min(a[x], a[y]));
        }
    }

    for (int i = 0; t[i][0]; ++i) {
        int x = t[i][0];
        if (a[x]) mov(t[i][1], t[i][2], x, a[x]);
    }

    if (a[0]) ch(0, 1, -a[0]);

    return 0;
}
