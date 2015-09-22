# include <bits/stdc++.h>
# define speedup cin.tie(0);ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;

const int maxn = 1e5+5;

vector<pii> vec;
int n, d;
lli sum[maxn];
int s[maxn], m[maxn];

void init() {
    speedup;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        pii cur;
        cin >> cur.first >> cur.second;
        vec.push_back(cur);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; ++i) {
        m[i] = vec[i].first;
        sum[i] = vec[i].second;
        if (i) sum[i] += sum[i-1];
    }
    lli ans = 0;
    for (int i = 0; i < vec.size(); ++i) {
        int t = upper_bound(m, m+n, m[i]-d)-m;
        lli tmp = sum[i];
        if (t < n) tmp -= sum[t-1];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}

void solve() {
}

int main()
{
    init();
    solve();

    return 0;
}
