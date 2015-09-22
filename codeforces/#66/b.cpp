# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,string> pis;

map<string,int> na;
vector<pis> vec;
multiset<int> b, c;

int n, m;

bool cmp(const pis &x, const pis &y) {
    return !(x.first>y.first || (x.first==y.first && x.second<y.second));
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str; int a;
        cin >> str >> a;
        na[str] = a;
        vec.push_back(make_pair(a, str));
    }
    sort(vec.begin(), vec.end(), cmp);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int val; cin >> val;
        b.insert(val);
    }
    for (int i = m; i < n; ++i) b.insert(0);
    string ta;
    cin >> ta;
    int val = na[ta] + *b.rbegin();
    c = b;
    auto itb = b.end();
    b.erase(--itb);
    int r = 1;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (it->second != ta) {
            auto iter = b.begin();
            if (it->second < ta) {
                iter = b.lower_bound(val - it->first);
            } else {
                iter = b.upper_bound(val - it->first);
            }
            if (iter != b.begin()) {
                --iter;
                b.erase(iter);
            } else {
                ++r;
            }
        }
    }
    cout << r << ' ';

    b = c;
    val = na[ta] + *b.begin();
    b.erase(b.begin());
    r = 1;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (it->second != ta) {
            auto iter = b.begin();
            if (it->second < ta) {
                iter = b.lower_bound(val - it->first);
            } else {
                iter = b.upper_bound(val - it->first);
            }
            if (iter != b.end()) {
                ++r;
                b.erase(iter);
            }
        }
    }
    cout << r << endl;

    return 0;
}
