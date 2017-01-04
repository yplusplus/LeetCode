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
    ListNode *reverse(ListNode *head) {
        ListNode *p = NULL;
        while (head) {
            ListNode *q = head->next;
            head->next = p;
            p = head;
            head = q;
        }
        return p;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode **p = &head;
        ListNode *a = NULL;
        while (a = *p) {
            int i = 0;
            ListNode *b = a;
            for (; i < k - 1 && b->next; i++) {
                b = b->next;
            }
            if (i < k - 1) break;
            ListNode *c = b->next;
            b->next = NULL;
            *p = reverse(a);
            a->next = c;
            p = &(a->next);
        }
        return head;
    }
};