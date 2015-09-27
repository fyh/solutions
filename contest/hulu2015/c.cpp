# include <cstring>
# include <algorithm>
# include <iostream>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

int n;
int ba;
int t[maxn];
lli lz[maxn];

void pre() {
    memset(lz, 0, sizeof(lz));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
}

int m;
void solve() {
    cin >> m;
    for (int i = 0; i < m; ++i) {
        lli l, r, w;
        cin >> l >> r >> w;
        int x = lower_bound(t, t+n, l) - t;
        int y = upper_bound(t, t+n, r) - t;
        for (int j = x; j < y; ++j) lz[j] += w;
    }
    for (int i = 0; i < n; ++i) {
        cout << lz[i] << endl;
    }
}

int main()
{
    pre();
    solve();
    return 0;
}

