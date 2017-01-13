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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p = NULL;
        ListNode *q = NULL;
        ListNode **ptail = &p;
        ListNode **qtail = &q;
        while (head) {
            if (head->val < x) {
                *ptail = head;
                ptail = &(head->next);
            } else {
                *qtail = head;
                qtail = &(head->next);
            }
            head = head->next;
        }
        *ptail = q;
        *qtail = NULL;
        return p;
    }
};