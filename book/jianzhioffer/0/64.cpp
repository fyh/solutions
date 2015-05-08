# include <vector>
# include <queue>
# include <iostream>
using namespace std;
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
	    if (size > num.size() || !size) return vector<int>();
	    vector<int> ret(num.size()-size+1, 0);
	    vector<int> Q(num.size()+1, 0);
	    int front = 0, rear = 0;
	    for (int i = 0; i < num.size(); ++i) {
	        while (front<rear && i-Q[front]+1>size) ++front;
	        while (front<rear && num[Q[rear-1]]<num[i]) --rear;
	        Q[rear++] = i;
	        if(i+1>=size) ret[i-size+1] = num[Q[front]];
	    }
	    return ret;
	}
};
vector<int> vec;

int main()
{
    int a[] = {2,3,4,2,6,2,5,1,0};
    for (int i = 0; a[i]; ++i) vec.push_back(a[i]);
    Solution s;
    vector<int> r = s.maxInWindows(vec, 0);
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }
    return 0;
}
