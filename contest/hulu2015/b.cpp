# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <set>
# include <iostream>
using namespace std;
typedef long long int lli;

const int maxn = 1005;

int N;
lli L[maxn];
lli D[maxn];
int r[maxn];

bool cmp(const int &a, const int &b) {
    return L[a]*D[b] <= L[b]*D[a];
}

int solve()
{
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> L[i] >> D[i];
        r[i] = i;
    }
    sort(r, r+N, cmp);
    lli ans = 0;
    lli ti = 0;
    for (int i = 0; i < N; ++i) {
        int j = r[i];
        ti += L[j];
        ans += ti*D[j];
    }
    cout << ans << endl;

    return 0;
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}
