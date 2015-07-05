/// unfinished..

# include <string>
# include <stdio.h>
# include <sstream>
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
private:
    string str;

    void hp(TreeNode *r, string &s)
    {
        if (!s.empty()) s+=' ';
        if (r == NULL) s += '#';
        else {
            stringstream ss;
            ss << r->val;
            s += ss.str();
            hp(r->left, s);
            hp(r->right, s);
        }
    }
public:
	char* Serialize(TreeNode *root) {
	    str = "";
	    hp(root, str);
	    return const_cast<char*>(str.c_str());
	}
	TreeNode* Deserialize(char *str) {
	}
};

TreeNode *root;

int main()
{
    root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);

    Solution s;

    printf("%s\n", s.Serialize(root));

    return 0;
}
