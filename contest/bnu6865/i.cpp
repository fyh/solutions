# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli n, m;
int a, b;
set<int> s1, s2;

int dist;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin >> n >> m >> a >> b) {
        s1.clear();
        s2.clear();
        dist = max(a, b);
        bool ex = false;
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            if (u > v) swap(u, v);
            if (u == 1 && v == n) {
                dist = min(dist, a);
                ex = true;
            }
            if (u == 1 && v != n) s1.insert(v);
            if (v == n && u != 1) s2.insert(u);
        }
        if (!ex) {
            dist = min(dist, b);
            for (set<int>::iterator it = s1.begin(); it != s1.end(); ++it) {
                if (s2.count(*it) > 0) {
                    dist = min(dist, a*2);
                    break;
                }
            }
        } else {
            for (int i = 2; i < n; ++i) {
                if (s1.count(i)<=0 && s2.count(i)<=0) {
                    dist = min(dist, b*2);
                    break;
                }
            }
        }
        cout << dist << endl;
    }

    return 0;
}
