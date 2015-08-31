# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n, m;
int a[105], c;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x < 0) a[c++] = x;
    }
    sort(a, a+c);
    int ans = 0;
    for (int i = 0; i < min(m, c); ++i) {
        ans += -a[i];
    }
    cout << ans << endl;

    return 0;
}
