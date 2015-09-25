# include <cstring>
# include <cstdio>
const int maxlen = 15;
const int maxw = 10;
const int maxn = 10005 * maxw;
char str[maxlen];
int n;
int root, id;
int next[maxn][maxw];
bool lc[maxn];
bool check_add(int e, int ch)
{
    if (next[e][ch]) return true;
    next[e][ch] = ++id;
    lc[id] = false;
    memset(next[id], 0, sizeof(next[id]));
    return false;
}
void solve(void)
{
    bool ans = true;
    scanf("%d", &n);
    id = 0;
    root = 0;
    lc[root] = false;
    memset(next[root], 0, sizeof(next[root]));
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        if (!ans) continue;
        int e = root;
        bool local = false;
        for (int j = 0; str[j]; ++j) {
            if ( !check_add(e, str[j]-'0') ) local = true;
            e = next[e][ str[j]-'0' ];
            if (lc[e]) ans = false;
        }
        lc[e] = true;
        if (!local) ans = false;
    }
    printf(ans ? "YES\n":"NO\n");
}
# define testin freopen("in.txt", "r", stdin)
int main()
{
    testin;
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
