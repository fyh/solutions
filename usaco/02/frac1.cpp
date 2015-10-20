/*
ID: yajunwf1
LANG: C++11
TASK: frac1
*/
# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

typedef pair<int,int> pii;
map<int,map<int,int> > M;

int gcd(int a, int b) {return !b ? a:gcd(b,a%b);}

bool cmp(const pii& a, const pii& b) {
    return a.first*b.second <= a.second*b.first;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    rdio(frac1);

    int n;
    cin >> n;
    vector<pii> ans;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            int t = gcd(i, j);
            int x = i / t, y = j / t;
            if (M[x].count(y) > 0) continue;
            ++M[x][y];
            ans.push_back(make_pair(y,x));
        }
    }
    ans.push_back(make_pair(0,1));
    ans.push_back(make_pair(1,1));
    sort(ans.begin(), ans.end(), cmp);

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << '/' << ans[i].second << endl;
    }

    return 0;
}
