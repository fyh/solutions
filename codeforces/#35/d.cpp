# include <bits/stdc++.h>
# define input freopen("input.txt", "r", stdin)
# define output freopen("output.txt", "w", stdout)
using namespace std;
typedef long long int lli;

const int maxn = 105;

lli n, X;
lli c[maxn];

int main()
{
    input;
    output;

    cin >> n >> X;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        c[i] = (n-i) * x;
    }
    sort(c, c+n);
    int cnt = 0;
    lli sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += c[i];
        if (sum > X) {
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;

    return 0;
}
