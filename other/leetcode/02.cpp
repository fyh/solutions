/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = 0;
        if (!l1 && !l2) return ret;
        if (!l1 || !l2) return !l1 ? l2:l1;

        ListNode* cur = ret;
        int carry = 0;
        for (;l1 || l2;) {
            if (!cur) ret = cur = new ListNode(0);
            else cur->next = new ListNode(carry), cur = cur->next;
            if (l1)
                cur->val += l1->val, l1 = l1->next;
            if (l2)
                cur->val += l2->val, l2 = l2->next;
            carry = cur->val / 10;
            cur->val %= 10;
        }
        while (carry) {
            cur->next = new ListNode(carry%10), cur = cur->next;
            carry /= 10;
        }
        return ret;
    }
};
