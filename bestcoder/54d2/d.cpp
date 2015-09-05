# include <iostream>
# include <vector>
# include <map>
# include <string.h>
using namespace std;

int gcd(int x, int y) {
    return !y ? x:gcd(y, x%y);
}

int n;
void solve() {
    cin >> n;
    ++n;
    int cnt = 0;
    for (int i = 2; i < n; ++i) {
        if (gcd(n, i) == 1) ++cnt;
    }
    cout << cnt+1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
