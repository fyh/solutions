# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1005;

int n;
int a[maxn];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], s += a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) if (n*a[i] > s) ++ans;
    cout << ans << endl;


    return 0;
}
