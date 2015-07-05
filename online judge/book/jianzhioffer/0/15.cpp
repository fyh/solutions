# include <stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
private:
    ListNode *head;
    ListNode *hp(ListNode *cur) {
        if (cur == NULL) return cur;
        else if (cur->next == NULL) {
            head = cur;
            head->next = NULL;
            return cur;
        } else {
            ListNode *t = hp(cur->next);
            cur->next = NULL;
            if (t) t->next = cur;
            return cur;
        }
    }
public:
	ListNode* ReverseList(ListNode* pHead) {
	    head = NULL;
	    hp(pHead);
	    return head;
	}
};

ListNode *head;
int main()
{
    head = new ListNode(-1);
    ListNode *cur = head;
    for (int i = 0; i < 10; ++i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    Solution s;
    head = s.ReverseList(head);
    for (;head != NULL;) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
