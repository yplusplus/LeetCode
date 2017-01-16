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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *new_head = NULL;
        ListNode **p = &new_head;
        ListNode *last = NULL;
        while (head) {
            if (last == NULL || head->val != last->val) {
                *p = head;
                last = head;
                p = &(head->next);
            }
            head = head->next;
        }
        *p = NULL;
        return new_head;
    }
};