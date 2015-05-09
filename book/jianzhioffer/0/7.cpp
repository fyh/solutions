# include <iostream>
# include <map>
# include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    map<int, int> m;
    struct TreeNode* hp(vector<int>&pre, vector<int>&in, int x, int y, int n) {
        if (n <= 0) return NULL;
        TreeNode *ret = new TreeNode( pre[x] );
        int p = m[ pre[x] ];
        ret->left = hp(pre, in, x+1, y, p-y);
        ret->right = hp(pre, in, x+1+p-y, p+1, n-1-p+y);
        return ret;
    }
public:
	struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
	    m.clear();
	    for (int i = 0; i < in.size(); ++i) {
            m[ in[i] ] = i;
	    }
	    TreeNode* ret = hp(pre, in, 0, 0, in.size());
	    return ret;
	}
};
vector<int> x;
vector<int> y;

int a[] = {1,2,3,4,5,6,7, 0};
int b[] = {3,2,4,1,6,5,7, 0};

int main()
{
    for (int i = 0; a[i]; ++i) x.push_back(a[i]), y.push_back(b[i]);

    Solution s;
    s.reConstructBinaryTree(x, y);

    return 0;
}
