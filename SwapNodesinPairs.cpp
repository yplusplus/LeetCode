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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *last = NULL;
        ListNode *new_head = NULL;
        while (head && head->next) {
            ListNode *p = head->next->next;
            head->next->next = head;
            if (new_head == NULL) {
                new_head = head->next;
            } else {
                last->next = head->next;
            }
            last = head;
            head = p;
        }
        last->next = head;
        return new_head;
    }
};