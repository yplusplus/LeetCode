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

// iteration
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
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        int n = getListLength(head);
        for (int i = 1; i < n; i <<= 1) {
            ListNode *new_head = NULL;
            ListNode **tail = &new_head;
            ListNode *p = NULL, *q = NULL;
            while (head) {
                p = head;
                q = splitList(p, i);
                head = splitList(q, i);
                mergeList(tail, p, q);
            }
            head = new_head;
        }
        return head;
    }
    int getListLength(ListNode *head) {
        int len = 0;
        for (; head; head = head->next, len++);
        return len;
    }
    ListNode *splitList(ListNode *head, int n) {
        for (int i = 1; i < n && head; i++) {
            head = head->next;
        }
        if (head == NULL) return NULL;
        ListNode *p = head->next;
        head->next = NULL;
        return p;
    }
    void mergeList(ListNode **&tail, ListNode *p, ListNode *q) {
        while (p && q) {
            if (p->val <= q->val) {
                *tail = p;
                tail = &(p->next);
                p = p->next;
            } else {
                *tail = q;
                tail = &(q->next);
                q = q->next;
            }
        }
        if (p) *tail = p;
        if (q) *tail = q;
        while (*tail) {
            tail = &(*tail)->next;
        }
    }
};