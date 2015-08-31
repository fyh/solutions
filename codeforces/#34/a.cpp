# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 105;

int n;
int dh = 1005, di = -1;
int a[maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    a[n] = a[0];
    for (int i = 0; i <= n; ++i) {
        if (i) {
            if (dh > abs(a[i]-a[i-1])) {
                dh = abs(a[i]-a[i-1]);
                di = i;
            }
        }
    }
    cout << di << ' ' << (di%n)+1 << endl;

    return 0;
}
