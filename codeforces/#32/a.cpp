# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

# define testin freopen("in.txt", "r", stdin)

int n;
int a[1005];
int d;

int main()
{
    cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i!=j && abs(a[j]-a[i])<=d) ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
