# include <algorithm>
# include <iostream>
using namespace std;
typedef long long int lli;
# define mid ((l+r)>>1)
# define lson l, mid, rt<<1
# define rson mid+1, r, rt<<1|1

const int maxn = 1e5+5;

int n, m;
int a[maxn];
lli b[maxn<<2];
lli c[maxn<<2];

void bu(lli *v, int rt) {
    v[rt] = v[rt<<1] + v[rt<<1|1];
}

void build(lli *v, int l, int r, int rt) {
    if (l == r) {v[rt] = 0; return ;}
    build(v, lson);
    build(v, rson);
    bu(v, rt);
}

void add(lli *v, int x, int dx, int l, int r, int rt) {
    if (l==r && l==x) {
        v[rt] += dx;
        return ;
    }
    if (x <= mid) add(v, x, dx, lson);
    else add(v, x, dx, rson);
    bu(v, rt);
}

lli query(lli *v, int x, int y, int l, int r, int rt) {
    if (x<=l&&r<=y) {
        return v[rt];
    }
    lli ret = 0;
    if (x <= mid) ret += query(v, x, y, lson);
    if (mid < y) ret += query(v, x, y, rson);
    return ret;
}

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        lli ti = 0;
        build(b, 1, n, 1);
        build(c, 1, n, 1);
        for (int i = m+1; i <= n; ++i) {
            add(b, a[i], 1, 1, n, 1);
            if (a[i] < n) ti += query(b, a[i]+1, n, 1, n, 1);
        }
        lli mx = ti;
        for (int i = m+1; i <= n; ++i) {
            add(c, a[i-m], 1, 1, n, 1);
            if (a[i-m] < n) ti += query(c, a[i-m]+1, n, 1, n, 1);
            if (a[i-m] > 1) ti += query(b, 1, a[i-m]-1, 1, n, 1);
            add(b, a[i], -1, 1, n, 1);
            if (a[i] < n) ti -= query(c, a[i]+1, n, 1, n, 1);
            if (a[i] > 1) ti -= query(b, 1, a[i]-1, 1, n, 1);
            mx = min(mx, ti);
        }
        printf("%lld\n", mx);
    }

    return 0;
}
