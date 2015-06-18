# include <bits/stdc++.h>
using namespace std;

int cd(int x) {
    int ret = 0;
    while (x > 0) {
        ++ret;
        x /= 10;
    }
    return ret;
}

long long int f10[15];
long long int pre[15];
void pp( void ) {
    f10[0] = 1;
    for (int i = 1; i < 15; ++i) {
        f10[i] = 10 * f10[i-1];
        pre[i] = i * 9 * f10[i - 1];
    }
}

bool solve() {
    long long int ans = 0;
    int x;
    if (EOF == scanf("%d", &x) ) return false;
    int d = cd(x);
    for (int i = 1; i < d; ++i) ans += pre[i];
    if (d <= 1) ans += x;
    else ans += d * (x-f10[d-1]+1);
    cout << ans << endl;
    return true;
}

# define testin freopen("data.in", "r", stdin)

int main()
{
    //testin;

    pp();

    solve();

    return 0;
}
