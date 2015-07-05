# include <vector>
# include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
		  val(x), next(NULL) {
    }
};
class Solution {
private:
    void help(struct ListNode* head, vector<int>&vec) {
        if (head) {
            help(head->next, vec);
            vec.push_back(head->val);
        }
    }
public:
	vector<int> printListFromTailToHead(struct ListNode* head) {
	    vector<int> ret;
	    help(head, ret);
	    return ret;
	}
};

