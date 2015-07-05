# include <bits/stdc++.h>

# define N 5

bool ok = true;
int cc[N][N];
int po[N*2][N], cp = 0;

typedef long long int lli;

void add_point(int x, int y) {
    bool ex = false;
    for (int i = 0;  i < cp; ++i) {
        if (po[i][0]==x && po[i][1]==y) {
            ++po[i][2];
            ex = true;
        }
    }
    if (!ex) {
        po[cp][0] = x, po[cp][1] = y, po[cp][2] = 1;
        ++cp;
    }
}

bool cross(lli x0, lli y0, lli x1, lli y1) {
    return (x0*x1 + y0*y1) == 0;
}

bool ck(int i, int j, int k1, int k2) {
    return cc[i][k1] == cc[j][k2];
}

bool check() {
    for (int i = 0; i < 4; ++i) {
        int x = cc[i][0]-cc[i][2], y = cc[i][1]-cc[i][3];
        if (x && y) {
            ok = false;
            return false;
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (po[i][2] != 2) {
            ok = false;
         //   puts("4");
            return false;
        }
        for (int j = i+1; j < 4; ++j) {
            if ((ck(i,j,0,0)&&ck(i,j,1,1)&&ck(i,j,2,2)&&ck(i,j,3,3)) ||
                (ck(i,j,0,2)&&ck(i,j,1,3)&&ck(i,j,2,0)&&ck(i,j,3,0))) {
                ok = false;
            //    puts("3");
                return false;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        int a = -1, b = -1, cnt = 0;
        for (int j = 0; j < 4; ++j) {
            if (cc[j][0]==po[i][0]&&cc[j][1]==po[i][1] ||
                cc[j][2]==po[i][0]&&cc[j][3]==po[i][1]) {
                ++cnt;
                if (a == -1) a = j;
                else b = j;
            }
        }
        if (cnt != 2 || !cross(cc[a][0]-cc[a][2], cc[a][1]-cc[a][3],
                cc[b][0]-cc[b][2], cc[b][1]-cc[b][3])) {
             //       puts("2");
            ok = false;
            return false;
        }
    }
    return true;
}

void read(void) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &cc[i][j]);
        }
        add_point(cc[i][0], cc[i][1]);
        add_point(cc[i][2], cc[i][3]);
        // degenerate case
        if (cc[i][0]==cc[i][2] && cc[i][1]==cc[i][3]) {
           //     puts("1");
            ok = false;
        }
    }
    if (cp != 4 || !check()) ok = false;
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    //testin;

    read();
    puts(ok ? "YES":"NO");

    return 0;
}
