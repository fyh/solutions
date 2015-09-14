# include <bits/stdc++.h>
using namespace std;
# define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long int lli;
typedef pair<int,int> pii;
typedef set<int> lis;

map<pii,lis> banList;
map<int,lis> linkTo;
map<pii,int> dist;
map<pii,int> pre;

int n, m, k;

void init() {
    cin >> n >> m >> k;
    rep(i, m) {
        int u, v; cin >> u >> v;
        linkTo[u].insert(v);
        linkTo[v].insert(u);
    }
    rep(i, k) {
        int x, y, z; cin >> x >> y >> z;
        banList[make_pair(x,y)].insert(z);
    }
}

void print_path(pii cur) {
    if (pre[cur] != -1) print_path(make_pair(pre[cur], cur.first));
    cout << cur.second << ' ';
}

void solve() {
    pii st = make_pair(0,1);
    queue<pii> Q;
    Q.push(st);
    dist[st] = 0;
    pre[st] = -1;
    // n >= 2
    while (Q.size()) {
        pii cur = Q.front(); Q.pop();
        for(int z : linkTo[cur.second]) {
            pii nxt = make_pair(cur.second, z);
            if (!dist.count(nxt) && !banList[cur].count(z)) {
                dist[nxt] = dist[cur] + 1;
                pre[nxt] = cur.first;
                if (z == n) {
                    cout << dist[nxt] << endl;
                    print_path(nxt);
                    cout << endl;
                    return ;
                }
                Q.push(nxt);
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    init();
    solve();

    return 0;
}
