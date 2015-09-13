i# include <iostream>
# include <map>
# include <vector>
# include <queue>
# include <cstring>
# include <algorithm>
# include <cstdio>
using namespace std;
typedef long long int lli;
# define testin freopen("in.txt", "r", stdin)

typedef pair<lli, lli> pii;

const int maxn = 1e4+5;

int n;
lli p[maxn], q[maxn];
int f[maxn];
vector< pii > P[maxn];
vector<int> G[maxn];

int ans = 1;

void dfs(int cur, int fa) {
    f[cur] = fa;
    for (int i = 0; i < G[cur].size(); ++i) {
        int x = G[cur][i];
        if (x != fa) {
            dfs(x, cur);
        }
    }
}

bool cmp(const pii &a, const pii &b) {
    if (a.first == b.first) return a.second >= b.second;
    return a.first >= b.first;
}

pii dfs2(int cur) {
    for (int i = 0; i < G[cur].size(); ++i) {
        int x = G[cur][i];
        if (x != f[cur]) {
            P[cur].push_back(dfs2(x));
        }
    }
    pii ret = make_pair(p[cur], q[cur]);
    sort(P[cur].begin(), P[cur].end(), cmp);
    for (int i = 0; i < P[cur].size(); ++i) {
        lli tmp = P[cur][i].first-ret.second;
        if (tmp < 0) tmp = 0;
        ret.first += tmp;
        ret.second += P[cur][i].second;
        if (tmp < 0) {
            ret.first += 0;
            ret.second = ret.second-tmp;
        } else {
            ret.first += tmp;
            ret.second = P[cur][i].second;
        }
    }
    return ret;
}

int main()
{
    // testin;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i+1] >> q[i+1];
    }
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0);
    pii ans = dfs2(1);
    cout << ans.first << endl;

	return 0;
}
