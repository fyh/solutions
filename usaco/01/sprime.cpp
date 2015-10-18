/*
ID: yajunwf1
LANG: C++11
TASK: sprime
*/
# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

map<int,bool> mp;

lli po(lli a, lli n, lli m) {
    lli ans = 1;
    for (lli h = a; n > 0; n >>= 1, h = h*h%m) {
        if (n&0x1) ans = ans*h%m;
    }
    return ans;
}
int pt[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,0};
bool miller_rabin(lli x, int MERR = 30) {
    // error < 1-(1/4)^MERR
    if (mp.count(x) > 0) return mp[x];
    if (x < 2) return false;
    for (int i = 0; pt[i]; ++i) {
        if (x%pt[i] == 0) return mp[x] = (x==pt[i]);
    }
    for (int i = 1; i < MERR; ++i) {
        if ( po(rand()%(x-1)+1,x-1,x) != 1) {
            return mp[x] = false;
        }
    }
    return mp[x] = true;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    rdio(sprime);

    int n;
    cin >> n;

    set<int> ans, tmp;
    for (int i = 1; i < 10; ++i) if (miller_rabin(i)) ans.insert(i);
    for (int i = 2; i <= n; ++i) {
        tmp.clear();
        for (auto it = ans.begin(); it != ans.end(); ++it) {
            for (int i = 1; i < 10; i+=2) {
                int t = *it * 10 + i;
                if (miller_rabin(t)) tmp.insert(t);
            }
        }
        ans.clear();
        ans = tmp;
    }
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
