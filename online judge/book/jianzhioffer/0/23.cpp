# include <vector>
class Solution {
bool hp(std::vector<int> &s, int x, int y) {
    if (x > y) return true;
    int i;
    for (i = x; i < y; ++i) {
        if (s[i] >= s[y]) {
            break;
        }
    }
    for (int j = i; j < y; ++j) {
        if (s[j] < s[y]) return false;
    }
    return hp(s, x, i-1) && hp(s, i, y-1);
}
public:
	bool VerifySquenceOfBST(std::vector<int> s) {
	    if (s.size() <= 0) return false;
	    return hp(s, 0, s.size()-1);
	}
};
