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
    void flatten(TreeNode* root, TreeNode *&prev) {
        if (root == NULL) return;
        flatten(root->right, prev);
        flatten(root->left, prev);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
    void flatten(TreeNode* root) {
        TreeNode *prev = NULL;
        flatten(root, prev);
    }
};