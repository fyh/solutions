# include <vector>
# include <iostream>
using namespace std;
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
	    vector<int> ret;
	    int m = matrix.size();
	    if (!m) return ret;
	    int n = matrix[0].size();
	    if (!n) return ret;
	    int lx = 0, ly = 0, rx = m-1, ry = n-1;
	    while (true) {
            if (lx > rx || ly > ry) break;
            for (int i = ly; lx <= rx && i <= ry; ++i) {
                ret.push_back(matrix[lx][i]);
            }
            ++lx;
            for (int i = lx; ly <= ry && i <= rx; ++i) {
                ret.push_back(matrix[i][ry]);
            }
            --ry;
            for (int i = ry; lx <= rx && i >= ly; --i) {
                ret.push_back(matrix[rx][i]);
            }
            --rx;
            for (int i = rx; ly <= ry && i >= lx; --i) {
                ret.push_back(matrix[i][ly]);
            }
            ++ly;
	    }
	    return ret;
	}
};

vector< vector<int> > m;

int a[] = {1,2, 3, 0};
int b[] = {6,5, 4, 0};

int main()
{
    vector<int> c;
    for (int i = 0; a[i]; ++i) c.push_back(a[i]);
    m.push_back(c);
    c.clear();
    for (int i = 0; b[i]; ++i) c.push_back(b[i]);
    m.push_back(c);

    Solution s;
    vector<int> r = s.printMatrix(m);
    for (int i = 0; i < r.size(); ++i) {
        std::cout << r[i] << std::endl;
    }

    return 0;
}
