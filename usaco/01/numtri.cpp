/*
ID: yajunwf1
LANG: C++11
TASK: numtri
*/
# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

int r;
int a[1005][1005];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    rdio(numtri);

    cin >> r;
    int ans = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
            a[i][j] += max(a[i-1][j-1], a[i-1][j]);
            ans = max(ans, a[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}
