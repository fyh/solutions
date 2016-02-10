# include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+5;
const int maxv = 20;

int n, m;
int a[maxn];
int mx[maxv][maxn];
int mn[maxv][maxn];

void init()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) mx[0][i] = mn[0][i] = i;
    for (int i = 1; (1<<i) < n; ++i) {
        for (int j = 0; j+(1<<i) <= n; ++j) {
            int x = mx[i-1][j], y = mx[i-1][j+(1<<(i-1))];
            mx[i][j] = a[x]>a[y] ? x:y;
            x = mn[i-1][j], y = mn[i-1][j+(1<<(i-1))];
            mn[i][j] = a[x]<a[y] ? x:y;
        }
    }
}

void query(int l, int r, int X) {
    int len = r - l + 1;
    int i = 0;
    for (; (1<<i) <= len ; ++i) ;
    --i;
    int x = mn[i][l], y = mn[i][r-(1<<i)+1];
    int lo = a[x]<a[y] ? x:y;
    x = mx[i][l], y = mx[i][r-(1<<i)+1];
    int hi = a[x]>a[y] ? x:y;

    if (a[lo] == a[hi]) {
        if (a[lo] != X) {
            cout << lo + 1;
        } else {
            cout << -1;
        }
    } else {
        if (a[lo] != X) {
            cout << lo + 1;
        } else {
            cout << hi + 1;
        }
    }
    cout << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    init();
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        query(l-1, r-1, x);
    }

    return 0;
}
