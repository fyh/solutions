# include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

int n;
int p[maxn];

int a[maxn], b[maxn], m;
int c[maxn];
int q[maxn], r;

int get(int x) {
    return x==p[x] ? x:p[x]=get(p[x]);
}

int main()
{
    // freopen("in.data", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) p[i] = i;
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        cin >> x >> y; --x, --y;
        if (get(x) == get(y)) {
            a[m] = x, b[m] = y;
            ++m;
        } else {
            p[get(x)] = get(y);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!c[get(i)]) q[r++] = get(i);
        ++c[get(i)];
    }
    if (r == m+1) {
        cout << m << endl;
        for (int i = 0; i < m; ++i) {
            cout << a[i]+1 << ' ' << b[i]+1 << ' ' << q[i]+1 << ' ' << q[i+1]+1 << endl;
        }
    } else {
        cout << r << ' ' << m << endl;
    }

    return 0;
}
