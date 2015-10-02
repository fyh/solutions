# include <stdio.h>
# include <string.h>
# include <iostream>
# include <algorithm>
# include <vector>
# include <map>
# include <set>
using namespace std;
typedef long long int lli;

const int maxn = 1005;

int fa[maxn];
int n, m;

int get(int x) {
    return x==fa[x] ? x:fa[x]=get(fa[x]);
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        fa[ get(a) ] = get(b);
    }
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (get(i) == get(1)) ++ans;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    for (;;) {
        cin >> n >> m;
        if (n==0 && m==0) break;
        solve();
    }

    return 0;
}
