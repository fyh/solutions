# include <vector>
# include <queue>
# include <iostream>
using namespace std;
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	    vector<int> vecr;
	    if (k > input.size() || !k) return vecr;
	    priority_queue<int> Q;
	    for (int i = 0; i < input.size(); ++i) {
            if (Q.size() < k) Q.push(input[i]);
            else if (Q.size() && input[i] < Q.top()) {
                Q.pop();
                Q.push(input[i]);
            }
	    }
	    vector<int> vec(Q.size(), 0);
	    for (int i = 0; i < vec.size(); ++i) {
            vec[vec.size()-i-1] = Q.top(); Q.pop();
	    }
	    return vec;
	}
};

int a[] = {4,5,1,6,2,7,3,8, 0};
int main ()
{
    vector<int> v;
    for (int i = 0; a[i]; ++i) v.push_back(a[i]);
    Solution s;
    vector<int> r = s.GetLeastNumbers_Solution(v, 4);
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }
    return 0;
}
