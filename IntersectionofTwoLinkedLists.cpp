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
    int getListLength(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);
        if (lenA < lenB) { swap(lenA, lenB); swap(headA, headB); }
        while (lenA > lenB) { headA = headA->next; lenA--; }
        while (headA != headB) { headA = headA->next, headB = headB->next; }
        return headA;
    }
};