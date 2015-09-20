# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# include <map>
# include <set>
using namespace std;

# define testin freopen("in.txt", "r", stdin)

int p, n;
map<int,bool> M;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    bool ok = true;
    cin >> p >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (M.count(x%p) > 0) {
            ok = false;
            cout << i << endl;
            break;
        } else {
            M[x%p] = true;
        }
    }
    if (ok) cout << -1 << endl;

    return 0;
}
