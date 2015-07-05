# include <stdio.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
int K;
TreeNode* ret;
    void walk(TreeNode* r) {
        if (r != NULL) {
            walk(r->left);
            --K;
            if (!K) ret = r;
            walk(r->right);
        }
    }
public:
	TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
	{
	    ret = NULL;
	    K = k;
	    walk(pRoot);
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
    TreeNode* t = s.KthNode(root, 3);
    printf("%d\n", t->val);

    return 0;
}
