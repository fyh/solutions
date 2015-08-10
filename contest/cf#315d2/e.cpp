# include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 205;

char s[30];
int L;
int n, m;
int g[maxn][maxn];
int f[maxn];
int co[maxn];
char t[maxn];
bool r[maxn];
int color = 1;

bool vis[maxn*3];
int in[300];

bool ok = true;

void check(int x, int c)
{
    if (!ok) return ;
    co[x] = c;
    for (int i = 0; i < n; ++i) if (g[x][i]) {
        int cc;
        if (g[x][i] > 0) cc = c;
        else cc = -c;
        if (!co[i]) check(i, cc);
        else if (co[i] != cc) {
            ok = false;
        }
    }
}

void init()
{
    scanf("%s%d%d", s, &n, &m);
    L = strlen(s);
    for (int i = 0; i < m; ++i) {
        char sx[5], sy[5];
        int x, y;
        scanf("%d%s%d%s", &x, sx, &y, sy); --x, --y;
        g[y][x] = g[x][y] = (sx[0]==sy[0] ? 1:-1);
        r[x] = r[y] = true;
    }
    scanf("%s", t);
    for (int i = 0; i < n; ++i) if (r[i] && !co[i]) check(i, color++);
    for (int i = 0; s[i]; ++i) {
        in[ i+'a' ] = (s[i] == 'V' ? 0:1);
    }
}

bool fi = false;

int ans[maxn];
int car[maxn];
int first[maxn];

bool les() {
    for (int i = 0; i < n; ++i) {
        if (t[i] > ans[i]) return false;
    }
    return true;
}


void dfs(int cur, bool eq)
{
    if (fi) return ;
    if (cur >= n) {
        if (les()) {
            fi = true;
            for (int i = 0; i < n; ++i) {
                putchar(ans[i]);
            }
            puts("");
        }
        return ;
    }
    if (co[cur] == 0) {
        if (eq) {
            for (int st = t[cur]; st < L+'a'; ++st) {
                ans[cur] = st;
                if (st == t[cur]) dfs(cur+1, true);
                else dfs(cur+1, false);
            }
        } else {
            for (int st = 'a'; st < L+'a'; ++st) {
                ans[cur] = st;
                dfs(cur+1, false);
            }
        }
    } else {
        int cC = std::abs( co[cur] );
        if (!car[cC]) {
            first[cC] = cur;
            for (int i = 0; i < 2; ++i) {
                car[cC] = i + 1;
                if (eq) {
                    for (int st = t[cur]; st < L+'a'; ++st) if (in[st] == i) {
                            ans[cur] = st;
                            if (st == t[cur]) {
                                dfs(cur+1, true);
                            } else {
                                dfs(cur+1, false);
                            }
                        }
                } else {
                    for (int st = 'a'; st < L+'a'; ++st) if (in[st] == i) {
                            ans[cur] = st;
                            dfs(cur+1, false);
                        }
                }
            }
        } else {
            int tmp = car[cC] - 1;
            if (co[cur] != co[ first[cC] ]) tmp = 1-tmp;
            for (int i = tmp; i <= tmp; ++i) {
                if (eq) {
                    for (int st = t[cur]; st < L+'a'; ++st) if (in[st] == i) {
                            ans[cur] = st;
                            if (st == t[cur]) dfs(cur+1, true);
                            else dfs(cur+1, false);
                        }
                } else {
                    for (int st = 'a'; st < L+'a'; ++st) if (in[st] == i) {
                            ans[cur] = st;
                            dfs(cur+1, false);
                        }
                }
            }
        }
    }
}

void solve()
{
    if (!ok) {
        puts("-1");
        return ;
    }

    dfs(0, true);

    if (!fi) puts("-1");
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    testin;

    init();
    solve();

    return 0;
}
