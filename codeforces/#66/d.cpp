# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e6+5;

int n, m, k;
int p[maxn];
map<int,int> C;

int get(int x) {return x==p[x] ? x:p[x]=get(p[x]);}
void add(int u, int v) {p[get(u)] = get(v);}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) p[i] = i;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) C[get(i)]++;
    if (k >= 2) {
        int c1 = 0;
        int c2 = 0;
        for (auto it = C.begin(); it != C.end(); ++it) {
            if (it->second == 1) ++c1;
            else c2 += min(k-2, it->second-2);
        }
        int l = c1 - c2 - 1;
        if (l < 0) l = 0;
        cout << l/2 << endl;
    } else {
        cout << max(0, (int)C.size()-2) << endl;
    }

    return 0;
}
