# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define speedup cin.tie(0), ios_base::sync_with_stdio(false)

const lli maxn = 1e5+5;
const lli maxc = 1e9+5;

map<lli,lli> M;
typedef map<lli,lli>::iterator itor;
/*
void d() {
    cout << "{" << endl;
    for (auto it = M.begin(); it != M.end(); ++it) {
        cout << it->second << ' ' << it->first << endl;
    }
    cout << "}" << endl;
}
*/
int main()
{
    speedup;

    M[maxn*maxc] = (lli)1;

    int n;

    cin >> n;
    while (n--) {
        lli s, c; cin >> s >> c;
        itor lo = M.lower_bound(s);
        if (lo->second < s) {
            M[s-1] = lo->second;
            M[lo->first] = s;
        }
        lo = M.lower_bound(s);
        itor cu = lo;
        while (true) {
            lli t = cu->first - cu->second + 1;
            if (t < c) {
                c -= t;
                ++cu;
            } else {
                lli ans;
                if (t == c) {
                    ans = cu->first;
                    ++cu;
                } else {
                    ans = cu->second + c - 1;
                    M[cu->first] = cu->second + c;
                }
                cout << ans << endl;;
                M.erase(lo, cu);
                //d();
                break;
            }
        }
    }

    return 0;
}
