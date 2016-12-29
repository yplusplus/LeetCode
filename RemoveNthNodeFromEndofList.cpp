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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && n > 0) {
            fast = fast->next;
            n--;
        }
        if (fast == NULL) {
            head = head->next;
        } else {
            while (fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = slow->next->next;
        }
        return head;
    }
};