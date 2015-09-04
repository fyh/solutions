# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 40;
const int maxm = 15;

int n, m;
int s, mc = maxn;
int c[maxm];
char g[maxm][maxn];

char t[maxn];

int st[maxn];

int ans;

void dfs(int cnt) {
    if (cnt == c[s]) {
        memcpy(t, g[s], sizeof(g[s]));
        for (int i = 0; i < cnt; ++i) {
            t[ st[i] ] = '1' + '0' - t[ st[i] ];
        }
        bool ok = true;
        for (int i = 0; i < m; ++i) {
            int cc = 0;
            for(int j = 0; j < n; ++j) {
                if (g[i][j] != t[j]) ++cc;
            }
            if (cc != c[i]) {
                ok = false;
                break;
            }
        }
        if (ok) ++ans;
    } else {
        int bg = (!cnt ? 0:st[cnt-1]+1);
        for (int i = bg; i+mc-cnt <= n; ++i) {
            st[cnt] = i;
            dfs(cnt+1);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> g[i] >> c[i];
        if (c[i] < mc) {
            mc = c[i];
            s = i;
        }
    }

    dfs(0);

    cout << ans << endl;

    return 0;
}
