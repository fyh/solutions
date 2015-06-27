// WA
//

# include <bits/stdc++.h>
# define testin freopen("in.txt", "r", stdin)

using namespace std;

const int maxn = 2e5+5;

typedef long long int lli;

int n, m;
lli l[maxn], R[maxn];
lli d[maxn];
lli g[maxn];
lli ans[maxn];
int r[maxn];
int rd[maxn];

bool cmp(const int &x, const int &y) {
    return g[x] < g[y];
}

bool cmpd(const int &x, const int &y) {
    return d[x] < d[y];
}

int main()
{
    testin;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%I64d%I64d", &l[i], &R[i]);
    for (int i = 0; i < m; ++i) scanf("%I64d", &d[i]), rd[i] = i;
    std::sort(rd, rd+m, cmpd);

    bool ok = true;
    int cnt = 0;
    int cz = 0;
    for (int i = 0; i < n-1; ++i) {
        g[i] = std::max(0LL, l[i+1]-R[i]);
        r[i] = i;
    }

    std::sort(r, r+n, cmp);

    int j = m - (n - 1);
    for (int i = 0; i < n-1; ++i) {
        if (g[ r[i] ] > d[ rd[j+i] ]) {
            ok = false;
            break;
        } else {
            ans[ r[i] ] = rd[j+i] + 1;
        }
    }

    if (ok) {
        puts("Yes");
        for (int i = 0; i < n-1; ++i) printf("%I64d ", ans[i]);
        puts("");
    } else puts("No");

    return 0;
}
