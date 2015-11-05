# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 2005 * 2;

int n;
lli a[maxn];
lli s[maxn];

int c[maxn], top;
lli p[maxn], q[maxn];

lli gcd(lli _a, lli _b) { return !_b ? _a:gcd(_b,_a%_b); }

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    for (int i = 1; i <= 2*n; ++i) s[i] = a[i] + s[i-1];
    cout << s[n] - s[0] << endl;

    if (n > 1) {
        lli ans = 0, si, sj;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j < i+n-1; ++j) {
                //cout << s[j]-s[i-1] << "\t" << s[i+n-1]-s[j] << "\t";
                lli tmp = gcd(s[j]-s[i-1], s[i+n-1]-s[j]);
                //cout << tmp << endl;
                if (tmp > ans) {
                    ans = tmp, si = i, sj = j;
                }
            }
        }
        cout << ans << endl;
        vector< pair<int,int> > vec;
        vec.push_back(make_pair(si, sj));
        vec.push_back(make_pair(sj+1, si+n-1));
        for (int i = 3; i <= n; ++i) {
            sort(vec.begin(), vec.end());
            for (int j = 0; j < vec.size(); ++j) {
                cout << s[vec[j].second] - s[ vec[j].first-1 ] << ' ';
            }
                cout << endl;
            p[0] = 0;
            for (int j = 1; j < vec.size(); ++j) {
                p[j] = gcd(p[j-1], s[vec[j].second] - s[vec[j].first-1]);
            }
            q[vec.size()] = 0;
            for (int j = vec.size()-1; j >= 0; --j) {
                q[j] = gcd(q[j+1], s[vec[j].second] - s[vec[j].first-1]);
            }
            lli tmp = 0;
            int tj, tk;
            for (int j = 0; j < vec.size(); ++j) {
                if (vec[j].second > vec[j].first) {
                    for (int k = vec[j].first; k < vec[j].second; ++k) {
                        lli tt = gcd(gcd(p[j],q[j]), gcd(s[k]-s[vec[j].first-1], s[vec[j].second]-s[k]));
                        if (tmp < tt) {
                            tmp = tt;
                            tj = j, tk = k;
                        }
                    }
                }
            }
            pair<int,int> p = vec[tj];
            vec.erase(vec.begin()+tj);
            vec.push_back(make_pair(p.first, tk));
            vec.push_back(make_pair(tk+1, p.second));
            cout << tmp << endl;
        }
    }

    return 0;
}
