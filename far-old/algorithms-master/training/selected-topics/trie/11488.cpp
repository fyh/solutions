// http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2483
# include <cstring>
# include <cstdio>
# include <algorithm>
const int maxw = 2;
const int maxlen = 205;
const int maxn = 50000 * maxw;
int n;
int root, id;
int cnt[maxn];
int next[maxn][maxw];
bool check_add(int e, int ch) {
    if (next[e][ch]) return true;
    next[e][ch] = ++id;
    cnt[id] = 0;
    memset(next[id], 0, sizeof(next[id]));
    return false;
}
char str[maxlen];
void solve()
{
    int ans = 0;
    scanf("%d", &n);
    root = 0;
    id = 0;
    cnt[root] = 0;
    memset(next[root], 0, sizeof(next[root]));
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        int e = root;
        for (int j = 0; str[j]; ++j) {
            check_add(e, str[j]-'0');
            e = next[e][ str[j]-'0' ];
            ++cnt[e];
            ans = std::max(ans, cnt[e]*(j+1));
        }
    }
    printf("%d\n", ans);
}
# define testin freopen("in.txt", "r", stdin)
int main()
{
    testin;
    int T;
    scanf("%d", &T);
    for (int ica = 0; ica < T; ++ica) {
        solve();
    }
    return 0;
}
