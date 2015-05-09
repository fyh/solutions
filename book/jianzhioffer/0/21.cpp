# include <iostream>
# include <vector>
# include <stack>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
	    if (pushV.size() != popV.size()) return false;
	    stack<int> S;
	    int j = 0;
	    for (int i = 0; i < pushV.size(); ++i) {
            int t = i;
            S.push( pushV[i] );
            while (j<pushV.size() && S.size() && S.top() == popV[j]) {
                S.pop();
                ++j;
            }
	    }
	    return j==pushV.size() && S.empty();
	}
};

int a[] = {1,2,3,4,5};
int b[] = {1, 2, 5,4,3};

vector<int> x;
vector<int> y;

int main()
{
    for (int i = 0; i < 5; ++i) x.push_back(a[i]), y.push_back(b[i]);
    Solution s;
    cout << s.IsPopOrder(x, y);

    return 0;
}
