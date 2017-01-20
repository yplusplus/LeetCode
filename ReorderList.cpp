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
        ListNode *new_head = NULL;
        while (head) {
            ListNode *p = head->next;
            head->next = new_head;
            new_head = head;
            head = p;
        }
        return new_head;
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode *p = head;
        ListNode *q = head;
        while (q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        q = reverse(p->next);
        p->next = NULL;
        p = head;
        while (p && q) {
            ListNode *next = p->next;
            p->next = q;
            p = next;
            next = q->next;
            q->next = p;
            q = next;
        }
    }
};