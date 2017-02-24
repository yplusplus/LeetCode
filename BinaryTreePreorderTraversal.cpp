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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        while (root != NULL) {
            if (root->left == NULL) {
                result.push_back(root->val);
                root = root->right;
                continue;
            }
            TreeNode *p = root->left;
            while (p->right && p->right != root) p = p->right;
            if (p->right == NULL) {
                result.push_back(root->val);
                p->right = root;
                root = root->left;
            } else {
                p->right = NULL;
                root = root->right;
            }
        }
        return result;
    }
};