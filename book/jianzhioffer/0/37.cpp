# include <algorithm>
# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
	int GetNumberOfK(vector<int> data ,int k) {
	    return upper_bound(data.begin(), data.end(), k) - lower_bound(data.begin(), data.end(), k);
	}
};
int a[] = {1,2,3,2,4,2,5,2,3,0};

int main()
{
    vector<int> v;
    for (int i = 0; a[i]; ++i) v.push_back(a[i]);
    sort(v.begin(), v.end());
    Solution s;
    cout << s.GetNumberOfK(v, 9);
    return 0;
}
