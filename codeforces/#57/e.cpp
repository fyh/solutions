# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 1e6+5;

int n;
int a[N];
int r[N];
int s[N];

bool cmp(const int &x, const int &y) {
    return a[x] <= a[y];
}

int lb(int p) {return p&-p;}

void add(int p, int d) {
    for (; p < N; p += lb(p)) {
        s[p] += d;
    }
}

int getSum(int r) {
    if (r == 0) return 0;
    int ret = 0;
    for (; r > 0; r-=lb(r)) ret += s[r];
    return ret;
}

lli getSum(int l, int r) {
    if (l > r) return 0;
    return getSum(r) - getSum(l-1);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], r[i]=i;
    sort(r, r+n, cmp);
    for (int i = 0; i < n; ++i) {
        a[ r[i] ] = i+1;
    }
    lli ans = 0;
    for (int i = 0; i < n; ++i) {
        // lower_bound set
        add(a[i], 1);
        lli x = a[i] - getSum(1, a[i]);
        lli y = getSum(a[i]+1, n);
        ans += x * y;
    }

    cout << ans << endl;

    return 0;
}
