# include <iostream>
# include <iomanip>
# include <cstdio>
typedef long long int lli;
using namespace std;
# define mid ((l+r)>>1)
# define lson l, mid, rt<<1
# define rson mid+1, r, rt<<1|1

const int maxn = 1e5+5;

int n, q;
lli a[maxn<<2];
lli lz[maxn<<2];

void bu(int rt) { a[rt] = a[rt<<1] + a[rt<<1|1]; }
// pass down
void pd(int l, int r, int rt) {
    if (lz[rt] != 0) {
        lz[rt<<1] += lz[rt];
        lz[rt<<1|1] += lz[rt];
        a[rt<<1] += (mid-l+1)*lz[rt];
        a[rt<<1|1] += (r-mid)*lz[rt];
        lz[rt] = 0;
    }
}

void db(int l, int r, int rt) {
    if (l == r) cout << setw(5) << a[rt];
    else {
        pd(l, r, rt);
        db(lson);
        db(rson);
    }
}

void build(int l, int r, int rt) {
    if (l == r) cin >> a[rt];
    else {
        build(lson);
        build(rson);
        bu(rt);
    }
}

void add(int x, int y, lli z, int l, int r, int rt) {
    if (x<=l && r<=y) a[rt]+=(r-l+1)*z, lz[rt] += z;
    else {
        pd(l, r, rt);
        if (x <= mid) add(x, y, z, lson);
        if (mid < y) add(x, y, z, rson);
        bu(rt);
    }
}

lli query(int x, int y, int l, int r, int rt) {
    if (x<=l && r<=y) return a[rt];
    pd(l, r, rt);
    lli ret = 0;
    if (x <= mid) ret += query(x, y, lson);
    if (mid < y) ret += query(x, y, rson);
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    build(1, n, 1);
    char od[5]; int x, y; lli z;
    for (int i = 0; i < q; ++i) {
        cin >> od >> x >> y;
        if (od[0] == 'C') { cin >> z; add(x, y, z, 1, n, 1); }
        else cout << query(x, y, 1, n, 1) << endl;
    }

    return 0;
}
