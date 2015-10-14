/*
ID: yajunwf1
LANG: C++11
TASK: milk
*/
# include <bits/stdc++.h>
using namespace std;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
typedef pair<int,int> pii;

const int maxn = 5005;

int n, m;
pii s[maxn];

int main()
{
    rdio(milk);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> s[i].first >> s[i].second;
    sort(s, s+m);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (n >= s[i].second) {
            n -= s[i].second;
            ans += s[i].first*s[i].second;
        } else {
            ans += n*s[i].first;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
