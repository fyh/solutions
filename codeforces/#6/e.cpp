# include <stdio.h>
# include <algorithm>

const int maxn = 1e5+5;
const int maxv = 17;

int a[maxn];
int l[maxn];
int n, k;

int m[2][maxv][maxn];

void prep(void) {
    for (int i = 0; i < n; ++i) m[0][0][i] = m[1][0][i] = a[i];
    for (int i = 1; i < maxv; ++i) {
        for (int j = 0; j+(1<<i) <= n; ++j) {
            m[0][i][j] = std::max(m[0][i-1][j], m[0][i-1][j+(1<<(i-1))]);
            m[1][i][j] = std::min(m[1][i-1][j], m[1][i-1][j+(1<<(i-1))]);
        }
    }
}

int q(int x, int y, int d)
{
    int j = 0;
    for (; (1<<j) <= (y-x+1); ++j); --j;
    if (j < 0) j = 0;
    return !d ? std::max(m[d][j][x], m[d][j][y-(1<<j)+1]):std::min(m[d][j][x], m[d][j][y-(1<<j)+1]);
}

int query(int x, int y) {
    return q(x, y, 0) - q(x, y, 1);
}

int bs(int i, int d) {
    int first = i, step, N = n-i;
    while (N > 0) {
        step = N / 2;
        int lo = first + step;
        if (query(i, lo) <= d) {
            first = lo + 1;
            N -= step + 1;
        } else N = step;
    }
    return first - i;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    // prepare();
    prep();
    int mx = 0, cc = 0;
    for (int i = 0; i < n; ++i) {
        l[i] = bs(i, k);
        if (mx < l[i]) mx = l[i], cc = 1;
        else if (mx == l[i]) ++cc;
    }
    printf("%d %d\n", mx, cc);
    for (int i = 0; i < n; ++i) {
        if (l[i] == mx) {
            printf("%d %d\n", i+1, i+mx);
        }
    }

    return 0;
}

