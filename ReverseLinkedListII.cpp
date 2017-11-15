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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) return NULL;
        ListNode *tail = NULL;
        if (m == 1) {
            ListNode *tail = NULL;
            ListNode *p = splitList(head, n - m + 1, tail);
            reverseList(head);
            head->next = p;
            return tail;
        } else {
            ListNode *p = splitList(head, m - 1, tail);
            ListNode *ptail = NULL;
            ListNode *q = splitList(p, n - m + 1, ptail);
            reverseList(p);
            p->next = q;
            tail->next = ptail;
            return head;
        }
    }
    ListNode *splitList(ListNode *head, int n, ListNode *&tail) {
        tail = NULL;
        for (int i = 1; i < n && head; i++, head = head->next);
        if (head == NULL) return head;
        ListNode *p = head->next;
        tail = head;
        head->next = NULL;
        return p;
    }
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = NULL;
        ListNode *next = NULL;
        while (head) {
            next = head->next;
            head->next = cur;
            cur = head;
            head = next;
        }
        return cur;
    }
};