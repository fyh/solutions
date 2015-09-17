# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 1005;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 1;
        for (int j = i; j+1 < n; ++j) {
            if (a[j+1] > a[j]) break;
            ++cur;
        }
        for (int j = i; j-1 >= 0; --j) {
            if (a[j-1] > a[j]) break;
            ++cur;
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;

    return 0;
}
