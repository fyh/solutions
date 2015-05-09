# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> n) {
	    int cc = 0;
	    int c;
	    for (int i = 0; i < n.size(); ++i) {
            if (cc <= 0) {
                c = n[i];
                cc = 1;
            } else {
                if (n[i] != c) {
                    --cc;
                } else {
                    ++cc;
                }
            }
	    }
	    int t = 0;
	    for (int i = 0; i < n.size(); ++i) {
            if (n[i] == c) ++t;
	    }
	    return t>=n.size()/2+1 ? c:0;
	}
};
int a[] = {1,2,3,2,4,2,5,2,3,0};

int main()
{
    vector<int> v;
    for (int i = 0; a[i]; ++i) v.push_back(a[i]);
    Solution s;
    cout << s.MoreThanHalfNum_Solution(v);
    return 0;
}
