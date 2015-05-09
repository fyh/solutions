# include <queue>
# include <vector>
# include <iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode *pRoot) {
		    vector<int> ret;
		    queue<TreeNode*> Q[2];
		    if (pRoot) Q[0].push(pRoot);
		    int i = 0;
		    while (true) {
		        if (Q[i].empty()) break;
		        while (Q[i].size()) {
		            TreeNode* it = Q[i].front(); Q[i].pop();
		            ret.push_back(it->val);
		            if (it->left) Q[1-i].push(it->left);
		            if (it->right) Q[1-i].push(it->right);
		        }
		        i = 1 - i;
		    }
		    return ret;
	}
};
TreeNode *root;

int main()
{
    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    Solution s;
    vector<int> t = s.PrintFromTopToBottom(root);
    for (int i = 0; i < t.size(); ++i) {
        cout << t[i];
        cout << endl;
    }

    return 0;
}

