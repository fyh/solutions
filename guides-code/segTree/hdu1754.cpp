# include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
# define mid ((l+r)>>1)
# define lson l, mid, rt<<1
# define rson mid+1, r, rt<<1|1

const int maxn = 2e5+5;
const lli INF = numeric_limits<lli>::min();

int n, m;
lli a[maxn<<2];

void bu(int rt) { a[rt] = max(a[rt<<1], a[rt<<1|1]); }

void build(int l, int r, int rt) {
    if (l == r) cin >> a[rt];
    else {
        build(lson);
        build(rson);
        bu(rt);
    }
}

lli query(int x, int y, int l, int r, int rt) {
    if (x<=l && r<=y) return a[rt];
    lli ret = -INF;
    if (x <= mid) ret = max(ret, query(x, y, lson));
    if (mid < y) ret = max(ret, query(x, y, rson));
    return ret;
}

void update(int x, int y, int l, int r, int rt) {
    if (l == r && l == x) a[rt] = y;
    else {
        if (x <= mid) update(x, y, lson);
        else update(x, y, rson);
        bu(rt);
    }
}

void solve() {
    build(1, n, 1);
    char od[5]; int x, y;
    while (m--) {
        cin >> od >> x >> y;
        if (od[0] == 'Q') {
            if (x > y) swap(x, y);
            cout << query(x, y, 1, n, 1) << endl;
        } else update(x, y, 1, n, 1);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin >> n >> m) {
        solve();
    }

    return 0;
}
