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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        ListNode *p = head;
        while (p) {
            length++;
            p = p->next;
        }
        if (length == 0) return head;
        k %= length;
        ListNode *slow = head;
        ListNode *fast = head;
        while (k) k--, fast = fast->next;
        while (fast->next) slow = slow->next, fast = fast->next;
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};