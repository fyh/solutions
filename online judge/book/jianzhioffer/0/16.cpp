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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
	    if (!pHead1 || !pHead2) return !pHead1 ? pHead2:pHead1;
	    ListNode *head = NULL;
	    ListNode *cur = head;
	    for (ListNode *tmp; pHead1 || pHead2; ) {
            if (pHead1 && pHead2) {
                if (pHead1->val < pHead2->val) {
                    tmp = pHead1;
                    pHead1 = pHead1->next;
                } else {
                    tmp = pHead2;
                    pHead2 = pHead2->next;
                }
            } else {
                if (pHead1) {
                    tmp = pHead1;
                    pHead1 = pHead1->next;
                } else {
                    tmp = pHead2;
                    pHead2 = pHead2->next;
                }
            }
            if (cur == NULL) {
                head = cur = tmp;
            } else {
                cur->next = tmp;
                cur = cur->next;
            }
	    }
        return head;
	}
};

ListNode*h1;
ListNode*h2;

void pr(ListNode *h) {
    if (h) {printf("%d\n", h->val); pr(h->next);}
}

int main()
{
    h1 = h2 = NULL;
    ListNode *c1 = h1;
    ListNode *c2 = h2;
    for (int i = 0; i < 10; ++i) {
        if (i&0x1) {
            if (h1 == NULL) {
                c1 = h1 = new ListNode(i);
            } else {
                c1->next = new ListNode(i);
                c1 = c1->next;
            }
        } else {
            if (h2 == NULL) {
                c2 = h2 = new ListNode(i);
            } else {
                c2->next = new ListNode(i);
                c2 = c2->next;
            }
        }
    }

    pr(h1);
    pr(h2);

    Solution s;
    ListNode *h = s.Merge(h1, h2);
    pr(h);

    for (;h;) {
        printf("%d\n", h->val);
        h = h->next;
    }

    return 0;
}
