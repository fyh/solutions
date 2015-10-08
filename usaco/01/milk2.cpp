/*
ID: yajunwf1
LANG: C++11
TASK: milk2
*/
# include <bits/stdc++.h>
using namespace std;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

typedef pair<int,int> pii;

int n;
vector<pii> vec;

int main()
{
    rdio(milk2);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        pii cur; cin >> cur.first >> cur.second;
        vec.push_back(cur);
    }
    sort(vec.begin(), vec.end());

    int a = 0, b = 0;
    int pre = vec[0].first, cur = vec[0].second;
    for (int i = 0; i < n; ++i) {
        if (vec[i].first > cur) {
            b = max(b, vec[i].first - cur);
            pre = vec[i].first;
        }
        cur = max(cur, vec[i].second);
        a = max(a, vec[i].second-pre);
    }

    cout << a << ' ' << b << endl;

    return 0;
}
