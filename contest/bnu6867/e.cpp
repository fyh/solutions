# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<double,int> pdi;

const int maxn = 1e4+5;

int n;
double a[maxn];
int ans[maxn], top;
vector< pdi > p, q;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (abs(a[i]) <= 1e-6) continue;
        if (a[i] > 0) p.push_back( make_pair(a[i], i+1) );
        else q.push_back( make_pair(a[i], i+1) );
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    reverse(p.begin(), p.end());

    for (int i = 0; i < p.size(); ++i) {
        if (p[i].first > 1) {
            ans[top++] = p[i].second;
        }
    }
    for (int i = 0; i+1 < q.size(); i += 2) {
        if (q[i].first * q[i+1].first > 1) {
            ans[top++] = q[i].second;
            ans[top++] = q[i+1].second;
        }
    }

    if (top <= 0) {
        if (p.size() > 0 && q.size() > 1)  {
            double x = p[0].first;
            double y = q[0].first * q[1].first;
            if (x > y) ans[top++] = p[0].second;
            else ans[top++] = q[0].second, ans[top++] = q[1].second;
        } else if (p.size() > 0) {
            ans[top++] = p[0].second;
        } else if (q.size() > 1) {
            ans[top++] = q[0].second, ans[top++] = q[1].second;
        } else {
            ans[top++] = q[0].second;
        }
    }

    cout << top << endl;
    sort(ans, ans+top);
    for (int i = 0; i < top; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
