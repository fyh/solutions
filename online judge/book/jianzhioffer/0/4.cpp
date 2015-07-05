# include <vector>
using namespace std;
class Solution {
public:
	bool Find(vector<vector<int> > array,int target) {
	    int m = array.size();
	    if (!m) return false;
	    int n = array[0].size();
	    if (!n) return false;
	    int x = 0, y = n-1;
	    while (true) {
	        if (array[x][y] == target) return true;
	        else if (array[x][y] > target) --y;
	        else ++x;
	        if (x >= m || y < 0) return false;
	    }
	    return false;
	}
};
