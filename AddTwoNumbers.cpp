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
        if (l1 == NULL && l2 == NULL) return NULL;
        int c = 0;
        ListNode *head = NULL;
        ListNode *last = NULL;
        while (l1 || l2 || c > 0) {
            int n = c;
            if (l1) {
                n += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                n += l2->val;
                l2 = l2->next;
            }
            ListNode *node = new ListNode(n % 10);
            if (head == NULL) head = node;
            if (last != NULL) last->next = node;
            last = node;
            c = n / 10;
        }
        return head;
    }
};