# include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	    if (k <= 0) return NULL;
	    ListNode *p = pListHead;
	    ListNode *q = pListHead;
	    for(int i = 0; i < k-1; ++i) {
            if (!q) break;
            q = q->next;
	    }
	    if (!q) return q;
	    for (;;) {
            q = q->next;
            if (!q) return p;
            p = p->next;
	    }
	    return NULL;
	}
};

ListNode * head;

int main()
{
    head = new ListNode(-1);
    ListNode *cur = head;
    for (int i = 0; i < 10; ++i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    Solution s;
    ListNode *q = s.FindKthToTail(head, 0);
    if (q) printf("%d\n", q->val);

    return 0;
}
