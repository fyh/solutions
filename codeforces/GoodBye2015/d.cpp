# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 5005;
const lli M = 1e9+7;

int n;
char ss[maxn];
lli f[maxn][maxn];
lli s[maxn][maxn];

int lcp[maxn][maxn];

void prep()
{
    for (int i = n; i > 0; --i)
    {
        for (int j = n; j > 0; --j)
        {
            if (ss[i]==ss[j]) lcp[i][j] = lcp[i+1][j+1]+1;
            else lcp[i][j] = 0;
        }
    }
}

bool jd(int i, int j, int k)
{
    if (lcp[i][j] >= k) return false;
    return ss[i+lcp[i][j]] > ss[j+lcp[i][j]];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> ss+1;
    prep();
    memset(f, -1, sizeof(f));
    lli ans = 0;
    for (int i = 1; i <= n; ++i) ans = (ans + dp(n, i))%M;
    cout << ans << endl;

    return 0;
}
