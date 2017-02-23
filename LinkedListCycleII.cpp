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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *p = head;
        ListNode *q = head;
        bool hasCycle = false;
        while (q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle) return NULL;
        p = head;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};