/*
ID: yajunwf1
LANG: C++11
TASK: wormhole
*/
# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

const int maxn = 15;

int n;
int x[maxn], y[maxn];
int b[maxn][maxn];

int h, r[maxn], l[maxn];

void init() {
    h = 0;
    for (int i = 0; i <= n; ++i) {
        l[i] = i - 1;
        r[i] = i + 1;
    }
    l[0] = n, r[n] = 0;
}

void del(int x) {
    r[l[x]] = r[x];
    l[r[x]] = l[x];
}

void rec(int x) {
    l[r[x]] = r[l[x]] = x;
}

void dfs(int &ans) {
    if (r[h] == h) {
        --ans;
        return ;
    }
    int c = r[h];
    del(c);
    for (int j = r[h]; j != h; j = r[j]) {
        if (!b[c][j]) {
            del(j);
            dfs(ans);
            rec(j);
        }
    }
    rec(c);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    // rdio(wormhole);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];

    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            b[i][j] = (x[i]==x[j]);
        }
    }
    for (int i = 1; i < n; i+=2) ans *= i;
    init();
    dfs(ans);
    cout << ans << endl;

    return 0;
}
