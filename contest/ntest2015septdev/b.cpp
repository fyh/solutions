# include <iostream>
# include <cctype>
# include <cstdio>
# include <cstring>
# include <algorithm>
# include <map>
# include <set>
# include <queue>
# include <vector>
using namespace std;
typedef long long int lli;

const int maxn = 105;
char s[maxn];

lli st[maxn], top;

lli getInt(int k) {
    lli ret = 0;
    for (int i = k; s[i]; ++i) {
        if (!isdigit(s[i])) return ret;
        ret = ret * 10 + (s[i] - '0');
    }
    return ret;
}

void solve() {
    top = 0;
    for (int i = 0; s[i]; ++i) {
        if (isdigit(s[i])) {
            lli cur = getInt(i);
            while (isdigit(s[i+1])) ++i;
            st[top-1] = st[top-1] * cur;
        } else if (s[i] == '(') {
            st[top++] = -1;
        } else if (s[i] == ')') {
            lli sum = 0;
            while (st[top-1] != -1) {
                sum += st[top-1];
                --top;
            }
            st[top-1] = sum;
            continue;
        } else {
            st[top++] = 1;
        }
    }
    lli ans = 0;
    for (int i = 0; i < top; ++i) {
        if (st[i] > 0) ans += st[i];
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        cin >> s;
        solve();
    }

    return 0;
}
