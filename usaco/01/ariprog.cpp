/*
ID: yajunwf1
LANG: C++11
TASK: ariprog
*/
# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

const int maxm = 250*250*2 + 5;

int n, m;

bool f[maxm];
int s[maxm], top;

void pre() {
    cin >> n >> m;
    for (int p = 0; p <= m; ++p) {
        for (int q = 0; q <= m; ++q) {
            f[p*p+q*q] = true;
        }
    }
    for (int i = 0; i <= m*m*2; ++i) {
        if (f[i]) s[top++] = i;
    }
}

typedef pair<int,int> pii;
vector<pii> ans;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    rdio(ariprog);

    pre();

    int cnt = 0;
    for (int i = 0; i+1 < top; ++i) {
        int md = s[i+1] - s[i];
        int st = s[i];
        for (int j = md; st+(n-1)*j <= s[top-1]; ++j) {
            bool ok = true;
            for (int k = 1; k < n; ++k) {
                if (!f[st+k*j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {ans.push_back(make_pair(j,st)); ++ cnt;}
        }
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < cnt; ++i) {
        cout << ans[i].second << ' ' << ans[i].first << endl;
    }

    if (!cnt) cout << "NONE" << endl;

    return 0;
}
