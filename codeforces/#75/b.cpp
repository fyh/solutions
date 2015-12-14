# include <bits/stdc++.h>
using namespace std;
# define speedup cin.tie(0), ios_base::sync_with_stdio(false)

typedef long long int lli;

const int maxn = 1e6+5;

char s[maxn];

int main()
{
    speedup;

    cin >> s;

    int ans = 0;
    int n = strlen(s);

    bool in = false;
    bool has1 = false;
    for (int i = n-1; i > 0; --i) {
        if (s[i] == '0') {
            if (!in) ++ans;
            else ans += 2;
        } else {
            in = true;
            has1 = true;
            ++ans;
        }
    }

    if (has1) ans += 2;

    cout << ans << endl;

    return 0;
}
