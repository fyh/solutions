# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define speedup cin.tie(0), ios_base::sync_with_stdio(false)

int n, m;
map<int, int> M;

int main()
{
    speedup;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++M[x];
    }

    bool ok = false;
    for (map<int,int>::iterator it = M.begin(); it != M.end(); ++it) {
        if (it->second > n/2) {
            cout << it->first << endl;
            ok = true;
        }
    }
    if (!ok) cout << '?' << endl;

    return 0;
}
