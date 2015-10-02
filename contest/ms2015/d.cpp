# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 105;
const int MOD = 1000000007;

int n;
int b[maxn][maxn];
int t[maxn][maxn];

void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &t[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &b[i][j]);
        }
    }
}

bool checkSum(int r0, int c0, int m)
{
    lli s1 = 0, s2 = 0;
    lli m1 = 1, m2 = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            s1 += t[i][j];
            s2 += b[i][j];
            m1 = (m1*t[i][j]) % MOD;
            m2 = (m2*b[i][j]) % MOD;
        }
    }
    // cout << "m = " << m << ", " << s1 << ' ' << s2 << ", " << m1 << ' ' << m2 << endl;
    return (s1==s2 && m1==m2);
}

bool eq(int r0, int c0, int m)
{
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (t[i+r0-1][j+c0-1] != b[i+r0-1][j+c0-1]) return false;
        }
    }
    return true;
}

int he[maxn][maxn];
void rot(int r0, int c0, int m, int k)
{
    if (k == 1) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                he[i+r0-1][j+c0-1] = t[m+1-j+r0-1][i+c0-1];
            }
        }
    } else if (k == 2) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                he[i+r0-1][j+c0-1] = t[m+1-i+r0-1][m+1-j+c0-1];
            }
        }
    } else if (k == 3) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                he[i+r0-1][j+c0-1] = t[j+r0-1][m+1-i+c0-1];
            }
        }
    }
    if (k > 0) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                t[i+r0-1][j+c0-1] = he[i+r0-1][j+c0-1];
            }
        }
    }
}

bool chk(int r0, int c0, int m)
{
    for (int i = 0; i < 4; ++i) {
        rot(r0, c0, m, i);
        if (m%2 == 0 && m != 2) {
            int mm = m / 2;
            if (!(checkSum(r0,c0,mm) && checkSum(r0, c0+mm, mm) && checkSum(r0+mm, c0, mm) && checkSum(r0+mm, c0+mm, mm)))
                continue;
            if (chk(r0, c0, mm) && chk(r0, c0+mm, mm) && chk(r0+mm, c0, mm) && chk(r0+mm, c0+mm, mm))
                return true;
        } else {
            if (eq(r0, c0, m)) return true;
        }
        rot(r0, c0, m, (4-i)%4);
    }
    return false;
}

void solve()
{
    if (!checkSum(1, 1, n)) {
        puts("No");
        return ;
    }

    if (chk(1, 1, n)) {
        puts("Yes");
    } else {
        puts("No");
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        solve();
    }

    return 0;
}
