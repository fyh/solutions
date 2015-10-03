# include <algorithm>
# include <iostream>
using namespace std;
typedef long long int lli;

const int maxn = 1005;

int n, m;
int a[maxn], b[maxn];

int main()
{
    int T; cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        sort(a, a+n);
        sort(b, b+n);
        reverse(b, b+n);
        int s1 = 0, s2 = 0;
        for (int i = 0; i < m; ++i) s1 += a[i], s2 += b[i];
        cout << (s1>s2 ? "YES":"NO") << endl;
    }

    return 0;
}
