# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

int n;
int a[maxn];

int m;
int b[maxn][2];

typedef pair<int,int> pii;
int d[maxn][2];

void init() {
    cin >> n;
    m = (n + 1) / 2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i < m) b[i][0] = a[i] - (i+1);
        else b[n-1-i][1] = a[i] - (n-i);
    }
    if (n%2 == 1) b[m][0] = b[m][1];
    for (int i = 0; i < m; ++i) {
        cout << b[i][0] << ' ' << b[i][1] << endl;
    }
}

void solve() {
    for (int i = 0; i <= m; ++i) d[i] = maxn; // inf
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (b[i][j] >= 0) {
                int k = upper_bound(d, d+i+1, b[i][j]) - d;
                id[k].push_back(make_pair(i,j));
                d[k] = b[i][j];
            }
        }
    }
}

int main()
{
    init();
    solve();

    return 0;
}
