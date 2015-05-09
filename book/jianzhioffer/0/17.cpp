# include <stdio.h>
# include <iostream>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
private:
    bool eq(TreeNode *x, TreeNode *y)
    {
        if (!y) return true;
        if (x && y) {
            if (x->val != y->val) return false;
            return eq(x->left, y->left) && eq(x->right, y->right);
        } else if (!x && !y) {
            return true;
        } else {
            return false;
        }
    }
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
	    if (pRoot2 == NULL) return false;
	    if (pRoot1 == NULL) return pRoot2 == NULL;
	    return eq(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
};

TreeNode *t1;
TreeNode *t2;

int main()
{
    t1 = new TreeNode(8);
    t1->left = new TreeNode(8);
    t1->left->left = new TreeNode(9);
    t1->left->right = new TreeNode(2);
    t1->left->right->left = new TreeNode(4);
    t1->left->right->right = new TreeNode(7);
    t1->right = new TreeNode(7);

    t2 = new TreeNode(8);
    t2->left = new TreeNode(9);
    t2->right = new TreeNode(2);

    Solution s;
    std::cout << s.HasSubtree(t1, t2) << std::endl;

    return 0;
}
