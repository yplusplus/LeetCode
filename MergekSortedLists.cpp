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
    struct cmp {
        bool operator()(const ListNode *lhs, const ListNode *rhs) const {
            return lhs->val > rhs->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> que;
        for (auto node : lists)
            if (node) que.push(node);
        if (que.empty()) return NULL;
        ListNode *head = NULL;
        ListNode *last = NULL;
        while (!que.empty()) {
            ListNode *node = que.top();
            que.pop();
            if (node->next)
                que.push(node->next);
            if (head == NULL) {
                head = node;
            } else {
                last->next = node;
            }
            last = node;
        }
        last->next = NULL;
        return head;
    }
};