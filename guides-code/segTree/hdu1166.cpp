# include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
# define mid ((l+r)>>1)
# define lson l, mid, rt<<1
# define rson mid+1, r, rt<<1|1
const int maxn = 5e4+5;
int n, q;
lli a[maxn<<2];
// bottom up
void bu(int rt) {
    a[rt] = a[rt<<1] + a[rt<<1|1];
}
void build(int l, int r, int rt) {
    if (l == r) {
        cin >> a[rt];
    } else {
        build(lson);
        build(rson);
        bu(rt);
    }
}
lli query(int x, int y, int l, int r, int rt) {
    if (x<=l && r<=y) return a[rt];
    lli ret = 0;
    if (x <= mid) ret += query(x, y, lson);
    if (y > mid) ret += query(x, y, rson);
    return ret;
}
void add(int id, int d, int l, int r, int rt) {
    if (l == r && l == id) {
        a[rt] += d;
        return ;
    }
    if (id <= mid) add(id, d, lson);
    else add(id, d, rson);
    bu(rt);
}
void solve()
{
    cin >> n;
    build(1, n, 1);
    for ( ; ; ) {
        char od[10];
        cin >> od;
        if (od[0] == 'E') break;
        int x, y;
        cin >> x >> y;
        if (od[0] == 'Q') cout << query(x, y, 1, n, 1) << endl;
        else {
            if (od[0] == 'S') y = -y;
            add(x, y, 1, n, 1);
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int ica = 1; ica <= T; ++ica) {
        cout << "Case " << ica << ":" << endl;
        solve();
    }

    return 0;
}
