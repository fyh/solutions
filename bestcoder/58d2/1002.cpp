# include <algorithm>
# include <iostream>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

bool v[maxn];
int a[maxn];
int b[maxn];
int pa[maxn];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i], pa[ a[i] ] = i;
        for (int i = 1; i <= n; ++i) cin >> b[i];
        for (int i = 1; i <= n; ++i) v[i] = false;
        int ans = 0;
        for (int i = 1; i <= n; ++i) if (!v[ a[i] ]) {
            int cur = 0;
            int x = i;
            for (;!v[a[x]];) {
                v[ a[x] ] = true;
                ++cur;
                x = pa[ b[x] ];
            }
            ans += (cur>1 ? cur-1:1);
        }
        cout << ans << endl;
    }

    return 0;
}
