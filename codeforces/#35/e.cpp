# include <bits/stdc++.h>
# define input freopen("input.txt", "r", stdin)
# define output freopen("output.txt", "w", stdout)
using namespace std;
typedef pair<int,int> pii;

int n;
vector<pii> p;
map<int,int> h;
vector<pii> ans;

int main()
{
    input;
    output;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int h, x, y;
        scanf("%d%d%d", &h, &x, &y);
        p.push_back(pii(x, -h));
        p.push_back(pii(y, +h));
    }
    sort(p.begin(), p.end());
    h.insert(pii(0, 1));
    for (auto e:p) {
        int x = h.rbegin()->first;
        if (e.second < 0) ++h[-e.second];
        else if (!--h[e.second]) h.erase(e.second);
        int y = h.rbegin()->first;
        if (x != y) {
            ans.push_back(pii(e.first, x));
            ans.push_back(pii(e.first, y));
        }
    }
    printf("%d\n", ans.size());
    for (auto e:ans) printf("%d %d\n", e.first, e.second);

    return 0;
}
