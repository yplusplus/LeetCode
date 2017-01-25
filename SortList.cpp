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
    ListNode *mergeSortedList(ListNode *left, ListNode *right) {
        if (left == NULL) return right;
        if (right == NULL) return left;
        ListNode p(0);
        ListNode *pp = &p;
        while (left && right) {
            if (left->val <= right->val) {
                pp->next = left;
                left = left->next;
            } else {
                pp->next = right;
                right = right->next;
            }
            pp = pp->next;
        }
        if (left) pp->next = left;
        else pp->next = right;
        return p.next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head;
        // find the middle node
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *right = slow->next;
        slow->next = NULL;
        // handle left and right recursively
        // merge two sorted list
        return mergeSortedList(sortList(head), sortList(right));
    }
};