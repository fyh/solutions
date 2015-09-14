# include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> me;
class Solution {
    bool prepared = false;
    void pre() {
        if (!prepared) {
            for (int i = 1; i*i <= 2e7; ++i) {
                me[i*i] = 1;
            }
            prepared = true;
        }
    }
    bool jd(int x, int l) {
        if (me.count(x)) return me[x] == l;
        if (l == 1) return me.count(x)>0;
        for (int i = 1; i*i*l <= x; ++i) {
            if( jd(x-i*i, l-1) ) return true;
        }
        return false;
    }
public:
    int numSquares(int n) {
        pre();
        for (int i = 1; i <= n; ++i) {
            if (jd(n, i)) {
                me[n] = i;
                return i;
            }
        }
    }
};

int main()
{
    Solution s;
    for (int i = 1; i < 10000; ++i) s.numSquares(i);

    return 0;
}
