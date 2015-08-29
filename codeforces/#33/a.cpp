# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n, m, k;
int c[1005];

int main()
{
    memset(c, 0x3f, sizeof(c));
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        c[x] = min(c[x], y);
    }

    int sum = 0;
    for (int i = 1; i <= m; ++i) sum += c[i];
    cout << min(sum, k) << endl;

    return 0;
}
