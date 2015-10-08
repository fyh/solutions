/*
ID: yajunwf1
LANG: C++11
TASK: crypt1
*/
# include <bits/stdc++.h>
using namespace std;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

int n;
set<int> vec;

set<int>s3, s2;

void add(set<int> &s, int x) {
    while (x > 0) {
        s.insert(x%10);
        x /= 10;
    }
}

bool jd(set<int> &s, int x) {
    while (x > 0) {
        if (vec.count(x%10) <= 0) return false;
        x/=10;
    }
    return true;
}

bool cb(int x, int a, int b) {
    int r = 0;
    while (x > 0) x/=10, ++r;
    return a<=r&&r<=b;
}

bool chk(int x, int y) {
    set<int> s;
    add(s, x);
    add(s, y);
    int t1 = x*(y%10), t2 = x*(y/10), t3 = x*y;
    return (cb(t1, 3, 3) && cb(t2, 3, 3) && cb(t3, 4, 4) && jd(s, t1) && jd(s, t2) && jd(s, t3));
}

bool isP(int x) {
    if (x < 2) return false;
    for (int i = 2; i*i <= x; ++i) {
        if (x%i == 0) return false;
    }
    return true;
}

int main()
{
    rdio(crypt1);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        //if (isP(x))
            vec.insert(x);
    }

    for (auto i = vec.begin(); i != vec.end(); ++i) {
        for (auto j = vec.begin(); j != vec.end(); ++j) {
            //if (isP(*i) && isP(*j))
                {
                s2.insert(*i * 10 + *j);
                for (auto k = vec.begin(); k != vec.end(); ++k) {
                    //if (isP(*k))
                    s3.insert(*i * 100 + *j * 10 + *k);
                }
            }
        }
    }

    int ans = 0;
    for (auto it = s3.begin(); it != s3.end(); ++it) {
        for (auto it2 = s2.begin(); it2 != s2.end(); ++it2) {
            if (chk(*it, *it2)) {
                ++ans;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
