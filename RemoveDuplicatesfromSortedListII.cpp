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
        ListNode *new_head;
        ListNode **p = &new_head;
        while (head) {
            ListNode *last = head;
            while (last->next != NULL && last->next->val == head->val) last = last->next;
            if (head == last) {
                *p = head;
                p = &(head->next);
            }
            head = last->next;
        }
        *p = NULL;
        return new_head;
    }
};