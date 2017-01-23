/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *last = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        // find the middle node
        while (fast->next && fast->next->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        // handle left-half recursively
        if (last != NULL) {
            last->next = NULL;
            root->left = sortedListToBST(head);
            last->next = slow;
        }
        // handle right-half recursively
        root->right = sortedListToBST(slow->next);
        return root;
    }
};