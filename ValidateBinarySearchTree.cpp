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
    bool isValid(TreeNode *p, TreeNode *&prev) {
        if (p == NULL) return true;
        if (!isValid(p->left, prev)) return false;
        if (prev != NULL && p->val <= prev->val) return false;
        prev = p;
        return isValid(p->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = NULL;
        return isValid(root, prev);
    }
};