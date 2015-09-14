# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;

int n;
int a[105];

int main()
{
    int ans = 0;

    cin >> n;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x%2 == 0) ans += x;
        else a[m++] = x;
    }
    int c = 0;
    sort(a, a+m);
    if (m > 0) ans += a[--m], ++c;
    for (int i = m-1; i-1 >= 0; i-=2) {
        ans += a[i] + a[i-1];
        ++c;
    }
    if (!c) ans = 0;
    cout << ans << endl;

    return 0;
}
