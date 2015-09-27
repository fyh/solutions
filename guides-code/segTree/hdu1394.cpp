# include <bits/stdc++.h>
using namespace std;
# define mid ( (l+r) >> 1 )
# define lson l, mid, rt<<1
# define rson mid+1, r, rt<<1|1

const int maxn = 5005;

int n;
int a[maxn*4];
int b[maxn];

void bu(int rt) { a[rt] = a[rt<<1] + a[rt<<1|1]; }

int query(int x, int y, int l, int r, int rt) {
    if (x<=l && r<=y) return a[rt];
    else {
        int ret = 0;
        if (x <= mid) ret += query(x, y, lson);
        if (mid < y) ret += query(x, y, rson);
        return ret;
    }
}

void update(int x, int l, int r, int rt) {
    if (l == r && l == x) ++ a[rt];
    else {
        if (x <= mid) update(x, lson);
        else update(x, rson);
        bu(rt);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin >> n) {
        memset(a, 0, sizeof(a[0])*n*4+1);
        int inv = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; ++x; b[i] = x;
            inv += query(x, n, 1, n, 1);
            update(x, 1, n, 1);
        }
        int ans = inv;
        for (int i = 0; i < n; ++i) {
            inv += n-2*b[i]+1;
            ans = min(ans, inv);
        }
        cout << ans << endl;
    }

    return 0;
}
