# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int last = -1;
        int ans = 1;
        map<char,int> M;
        for (int i = 0; i < s.length(); ++i) {
            if (M.count(s[i]) > 0) {
                last = max(last, M[s[i]]);
            }
            M[s[i]] = i;
            ans = max(ans, i-last);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.lengthOfLongestSubstring("eee");

    return 0;
}
