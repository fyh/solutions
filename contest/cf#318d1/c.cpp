# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

int n;
int cs[maxn];
int c3[maxn];
int f3[maxn];
int cf[maxn];
int fa[maxn];

int p[maxn];
int q[maxn];
vector<int> g[maxn];


int dfs11(int cur, int ff) {
    fa[cur] = ff;
    p[cur] = g[cur].size() - 1;
    for (int i = 0; i < g[cur].size(); ++i) {
        int v = g[cur][i];
        if (v != ff) {
            p[cur] += dfs11(v, cur) - 1;
        }
    }
    return p[cur];
}

int dp11(int cur) {
    if (q[cur]!=-1) return q[cur];
    if (cur == 0) return q[cur] = 1;
    q[cur] = g[ fa[cur] ].size()-1;
    for (int i = 0; i < g[ fa[cur] ].size(); ++i) {
        int v = g[ fa[cur] ][i];
        if (v == fa[ fa[cur] ]) {
        } else {
            q[cur] += p[v] - 1;
        }
    }
    q[cur] += dp11( fa[cur] ) - 1;
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
        if (v != fa[cur]) {
            dfs22(v, ok);
        }
    }
}




int dfs(int cur, int fat) {
    fa[cur] = fat;
    cs[cur] = g[cur].size()-1;
    for (int i = 0; i < g[cur].size(); ++i) {
        int v = g[cur][i];
        if (v != fat) {
            cs[cur] = max(cs[cur], dfs(v, cur));
        }
    }
    return cs[cur];
}

int dp(int cur) {
    if (cur == 0) return 0;
    int ret = g[fa[cur]].size()-1;
    for (int i = 0; i < g[fa[cur]].size();++i) {
        int v = g[fa[cur]][i];
        if (v!=cur) {
            ret = max(ret, cs[v]);
        }
    }
    ret = max(ret, dp(fa[cur]));
    return cf[cur] = ret;
}

int dp3(int cur) {
    if (cur == 0) return 0;
    f3[cur] = 0;
    for (int i = 0; i < g[ fa[cur] ].size(); ++i) {
        int v = g[ fa[cur] ][i];
        if (v != cur) {
            f3[cur] = max(f3[cur], c3[v]);
        }
    }
    if (g[ fa[cur] ].size()-1 >= 3) f3[cur] = max(1, f3[cur]);
    f3[cur] = max(f3[cur], dp3(fa[cur]));
    return f3[cur];
}

void dfs2(int cur, bool& ok) {
    if (!ok) return ;
    if (g[cur].size()>=3) {
        cnt = 0;
        for (int i = 0; i < g[cur].size(); ++i) {
            int v = g[cur][i];
            if (v == fa[cur]) {
                arr[cnt++] = cf[v];
            } else {
                arr[cnt++] = cs[v];
            }
        }
        sort(arr, arr+cnt);
        if (arr[cnt-1]>=3&&arr[cnt-2]>=2&&arr[cnt-3]>=2) {
            ok = false;
            return ;
        }
    }
    for (int i = 0; ok && i < g[cur].size(); ++i) {
        int v = g[cur][i];
        if (v != fa[cur]) {
            dfs2(v, ok);
        }
    }
}

int dfs3(int cur) {
    c3[cur] = 0;
    for (int i = 0; i < g[cur].size(); ++i) {
        int v = g[cur][i];
        if (v != fa[cur]) {
            c3[cur] += dfs3(v);
        }
    }
    if (g[cur].size()>3) c3[cur] = max(c3[cur], 1);
    return c3[cur];
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    g[0].push_back(1);
    g[1].push_back(0);

    dfs11(1, 0);
    for (int i = 0; i <= n; ++i) dp11(i);

    bool ok = true;
    dfs22(1, ok);


    dfs(1, 0);
    for (int i = 0; i <= n; ++i) dp(i), dp3(i);
    dfs3(0);
    for (int i = 0; i <= n; ++i) {
        if (c3[i]+f3[i] >= 3) {
            ok = false;
            break;
        }
    }
    dfs2(1, ok);
    cout << (ok ? "Yes":"No") << endl;

    return 0;
}
