/*
ID: yajunwf1
LANG: C++11
TASK: barn1
*/
# include <bits/stdc++.h>
using namespace std;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

const int maxs = 205;

int m, s, c;
bool mk[maxs];
int it[maxs], top;

int main()
{
    rdio(barn1);

    memset(mk, true, sizeof(mk));

    cin >> m >> s >> c;
    for (int i = 0; i < c; ++i) {
        int x; cin >> x;
        mk[x] = false;
    }

    int ans = c;

    int p = 1, q = s;
    for (;p<=s && mk[p]; ++p) ;
    for (;q>=1 && mk[q]; --q) ;

    if (p > q) cout << ans << endl;
    else {
        for (int i = p; i < q; ++i) {
            if (mk[i]) {
                int t = 0;
                while (mk[i+t]) ++t;
                i += t; // ok
                it[top++] = t;
            }
        }
        sort(it, it+top);
     //   reverse(it, it+top);
        if (top+1 <= m) cout << ans << endl;
        else {
            for (int i = 0; i < top+1-m; ++i) {
                ans += it[i];
            }
            cout << ans << endl;
        }
    }

    return 0;
}
