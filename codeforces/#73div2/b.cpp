# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

typedef pair<int,int> pii;

const int maxn = 5e5+5;

int n, m, x;
vector<pii> p[255];
bool v[255];

int d2[255];

char s[35];
char t[maxn];

int sqr(int num) {return num*num;}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; s[j]; ++j) {
            p[ s[j] ].push_back( make_pair(i+1, j+1) );
            v[ s[j] ] = true;
        }
    }

    for (int i = 'A'; i <= 'Z'; ++i) {
        d2[i] = m*m*n*m+1;
        for (int j = 0; j < p['S'].size(); ++j) {
            for (int k = 0; k < p[tolower(i)].size(); ++k) {
                d2[i] = min(d2[i], sqr(p['S'][j].first-p[tolower(i)][k].first)+sqr(p['S'][j].second-p[tolower(i)][k].second));
            }
        }
    }

    int q;
    cin >> q >> t;

    int ans = 0;
    bool ok = true;
    for (int i = 0; i < q; ++i) {
        if (!v[tolower(t[i])]) { ok = false; break; }
        if (isupper(t[i])) {
            if (!v['S']) { ok = false; break; }
            else if (d2[t[i]] > x*x) ++ans;
        }
    }

    if (!ok) ans = -1;
    cout << ans << endl;

    return 0;
}
