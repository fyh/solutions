# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;
int r[55], c[55];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n*n; ++i) {
        int x, y; cin >> x >> y;
        if (r[x] || c[y]) continue;
        cout << i+1 << ' ';
        r[x] = 1, c[y] = 1;
    }

    return 0;
}
