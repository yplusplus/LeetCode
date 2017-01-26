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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *new_head = NULL;
        while (head) {
            ListNode *next = head->next;
            if (new_head == NULL || new_head->val > head->val) {
                head->next = new_head;
                new_head = head;
            } else {
                ListNode *p = new_head;
                while (p->next != NULL && p->next->val < head->val) p = p->next;
                head->next = p->next;
                p->next = head;
            }
            head = next;
        }
        return new_head;
    }
};