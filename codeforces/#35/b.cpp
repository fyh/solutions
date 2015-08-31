# include <bits/stdc++.h>
# define input freopen("input.txt", "r", stdin)
# define output freopen("output.txt", "w", stdout)
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;

int n, m, k;
map<string, bool> ex;
map<string, pii> po;
map<pii, bool> oc;

void go(int x, int y, string id) {
    while (true) {
        pii p = make_pair(x, y);
        if (!oc[p]) {
            po[id] = p;
            oc[p] = true;
            ex[id] = true;
            break;
        } else {
            ++y;
            if (y > m) {
                y = 1;
                ++x;
                if (x > n) break;
            }
        }
    }
}

int main()
{
    input;
    output;

    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
        int od, x, y; string id;
        cin >> od;
        if (od == 1) {
            cin >> x >> y >> id;
            go(x, y, id);
        } else {
            cin >> id;
            if (!ex[id]) {
                cout << -1 << ' ' << -1 << endl;
            } else {
                pii p = po[id];
                ex[id] = false;
                oc[p] = false;
                cout << p.first << ' ' << p.second << endl;
            }
        }
    }

    return 0;
}
