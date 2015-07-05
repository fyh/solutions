# include <vector>
# include <iostream>
using namespace std;
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
        vector<int> b(A.size()+1, 1);
        for (int i = A.size()-1; i >= 0; --i) {
            b[i] = b[i+1] * A[i];
        }
        int t = 1;
        vector<int> ret(A.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            ret[i] = t * b[i+1];
            t = t * A[i];
        }
        return ret;
	}
};

vector<int> v;

int main()
{
    for (int i = 1; i < 5; ++i) v.push_back(i);
    Solution s;
    vector<int> r = s.multiply(v);
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }

    return 0;
}
