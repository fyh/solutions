# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

int n;
vector<int> g[maxn];

int p[maxn];
int q[maxn];
int f[maxn];

int dfs11(int cur, int fa) {
    f[cur] = fa;
    p[cur] = g[cur].size() - 1;
    for (int i = 0; i < g[cur].size(); ++i) {
        int v = g[cur][i];
        if (v != fa) {
            p[cur] += dfs11(v, cur) - 1;
        }
    }
    return p[cur];
}

int dp(int cur) {
    if (q[cur]!=-1) return q[cur];
    if (cur == 0) return q[cur] = 1;
    q[cur] = g[ f[cur] ].size()-1;
    for (int i = 0; i < g[ f[cur] ].size(); ++i) {
        int v = g[ f[cur] ][i];
        if (v == f[ f[cur] ]) {
        } else {
            q[cur] += p[v] - 1;
        }
    }
    q[cur] += dp( f[cur] ) - 1;
    return q[cur];
}

int arr[maxn], cnt;

void dfs22(int cur, bool &ok) {
    if (!ok) return ;
    if (g[cur].size()>=3) {
        cnt = 0;
        for (int i = 0; i < g[cur].size(); ++i) {
            int v = g[cur][i];
            arr[cnt++] = q[v] + p[v];
        }
        sort(arr, arr+cnt);
        if (arr[cnt-1]>=3&&arr[cnt-2]>=3&&arr[cnt-3]>=3) {
            ok = false;
            return ;
        }
        if (arr[cnt-1]>=3&&arr[cnt-2]>=3&&g[cur].size()>=5) {
            ok = false;
            return ;
        }
    }
    for (int i = 0; ok && i < g[cur].size(); ++i) {
        int v = g[cur][i];
        if (v != f[cur]) {
            dfs22(v, ok);
        }
    }
}

int main()
{
    memset(q, -1, sizeof(q));
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs11(1, 0);
    for (int i = 0; i <= n; ++i) dp(i);

    bool ok = true;
    dfs22(1, ok);

    cout << (ok ? "Yes":"No") << endl;

    return 0;
}

