# include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> me;
class Solution {
    bool jd(int x, int l) {
        if (l == 1) return me.count(x)>0;
        for (int i = 1; i*i*l <= x; ++i) {
            if( jd(x-i*i, l-1) ) return true;
        }
        return false;
    }
public:
    int numSquares(int n) {
        for (int i = 1; i*i <= n; ++i) {
            me[i*i] = true;
        }
        for (int i = 1; i <= n; ++i) {
            if (jd(n, i)) return i;
        }
    }
};

int main()
{
    Solution s;
    for (int i = 1; i < 100000; ++i) cout << s.numSquares(i);

    return 0;
}
