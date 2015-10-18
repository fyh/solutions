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

int r[maxn];

void pre() {
    for (int i = 1; i <= n; ++i) {
        int tj = 0, tx = 2e9;
        for (int j = 1; j <= n; ++j) if (j!=i && y[j]==y[i] && x[j]>x[i]) {
            if (x[j] < tx) {
                tx = x[j];
                tj = j;
            }
        }
        r[i] = tj;
    }
}

int go[maxn];

bool f[maxn];
bool chk() {
    for (int i = 1; i <= n; ++i) {
        memset(f, false, sizeof(f));
        int s = i;
        while (true) {
            if (f[s]) return true;
            f[s] = true;
            s = go[s];
            s = r[s];
            if (!s) break;
        }
    }
    return false;
}

int v[maxn];
int ans = 0;
void make(int cnt) {
    if (cnt >= n) {
        if (chk()) ++ans;
        return ;
    }
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) {
            v[i] = true;
            for (int j = i+1; j <= n; ++j) {
                if (!v[j]) {
                    v[j] = true;
                    go[i] = j;
                    go[j] = i;
                    make(cnt+2);
                    v[j] = false;
                }
            }
            v[i] = false;
            break;
        }
    }
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    rdio(wormhole);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];

    pre();
    make(0);

    cout << ans << endl;

    return 0;
}
