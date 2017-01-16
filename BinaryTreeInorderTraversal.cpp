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
    vector<int> inorderTraversal(TreeNode* root) {
        // morris traversal
        TreeNode *cur = root;
        vector<int> result;
        while (cur) {
            if (cur->left == NULL) {
                result.push_back(cur->val);
                cur = cur->right;
            } else {
                // find Precursor
                TreeNode *p = cur->left;
                while (p->right != NULL && p->right != cur) p = p->right;
                if (p->right == NULL) {
                    p->right = cur;
                    cur = cur->left;
                } else {
                    p->right = NULL;
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};