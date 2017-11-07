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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *new_head = NULL;
        ListNode **p = &new_head;
        while (head) {
            if (head->val != val) {
                *p = head;
                p = &(head->next);
            }
            head = head->next;
        }
        *p = NULL;
        return new_head;
    }
};