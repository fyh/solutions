# include <vector>
# include <iostream>
using namespace std;
class Solution {
public:
	int minNumberInRotateArray(vector<int> a) {
	    if (a.empty()) return 0;
	    int l = 0, r = a.size()-1;
	    while (l < r) {
            if (a[l] > a[r]) {
                int mid = l + (r - l) / 2;
                if (a[l] <= a[mid]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                int ret = a[l];
                for (int i = l; i <= r; ++i) ret = min(ret, a[i]);
                return ret;
            }
	    }
	    return a[l];
	}
};

int a[] = {1,1,-1,0};

vector<int> v;

int main()
{
    for (int i = 0; a[i]; ++i) v.push_back(a[i]);
    Solution s;
    std::cout << s.minNumberInRotateArray(v) << std::endl;
    return 0;
}
