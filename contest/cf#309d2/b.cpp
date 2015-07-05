# include <bits/stdc++.h>

# define testin freopen("in.txt", "r", stdin)

const int maxn = 105;

int n;

char r[maxn][maxn];
char s[maxn][maxn];

int chk() {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '0') {
                ok = false;
                break;
            }
        }
        if (ok) ++ret;
    }
    return ret;
}

int swep(int row, int &tmp) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (s[row][i] == '0') {
            ++ret;
            for (int j = 0; j < n; ++j) {
                s[j][i] = '1' + '0' - s[j][i];
            }
        }
    }
    tmp = chk();

    return ret;
}

void cpy() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i][j] = r[i][j];
        }
    }
}

int main()
{
    testin;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", r[i]);
    cpy();

    int ans = chk();
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        int cnt = swep(i, tmp);
        if (ans < tmp) {
            ans = tmp;
        }
        cpy();
    }

    std::cout << ans << std::endl;

    return 0;
}
