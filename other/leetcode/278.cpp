# include <bits/stdc++.h>
using namespace std;

vector<bool> vec = {false,true};

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
    return vec[version];
}

class Solution {
public:
    int firstBadVersion(int n) {
        int fi = 1, co = n, st;
        while (co > 0) {
            st = co / 2;
            int tm = fi + st;
            if (!isBadVersion(tm)) {
                fi = ++tm;
                co -= st+1;
            } else co = st;
        }
        return fi;
    }
};

int main()
{
    Solution s;
    cout << s.firstBadVersion(vec.size()-1) << endl;

    return 0;
}
