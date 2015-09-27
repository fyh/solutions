# include <string.h>
# include <iostream>
# include <stdio.h>

using namespace std;

# define testin freopen("in.txt", "r", stdin)
# define rep(n) for (int i = 0; i < n; ++i)
# define clr(x) memset(x, 0, sizeof(x))

const int maxn = 100005;

int n, t;
int a[maxn], b[maxn];

int main()
{
    testin;

    cin >> n >> t;
    rep(n) cin >> a[i] >> b[i];
    int st = 1;
    int ans = 0;
    rep(n) {
        ans += b[i]-a[i]+1+(a[i]-st)%t;
        st = b[i]+1;
    }
    cout << ans << endl;

    return 0;
}
