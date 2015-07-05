# include <vector>
using namespace std;
class Solution {
public:
	void reOrderArray(vector<int> &arr) {
	    vector<int> tmp(arr.size(), 0);
	    int j = 0;
	    for (int i = 0; i < arr.size(); ++i) {
            if (arr[i]&0x1) tmp[j++] = arr[i];
	    }
	    for (int i = 0; i < arr.size(); ++i) {
            if (!(arr[i]&0x1)) tmp[j++] = arr[i];
	    }
	    for (int i = 0; i < arr.size(); ++i) {
            arr[i] = tmp[i];
	    }
	}
};
