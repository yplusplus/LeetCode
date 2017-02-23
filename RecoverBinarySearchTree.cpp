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
    void recoverTree(TreeNode *root) {
        TreeNode *p = NULL;
        TreeNode *q = NULL;
        TreeNode *o = NULL;
        while (root) {
            TreeNode *prev = NULL;
            if (root->left) {
                prev = root->left;
                while (prev->right && prev->right != root) prev = prev->right;
            }
            if (prev && prev->right == NULL) {
                prev->right = root;
                root = root->left;
            } else {
                if (prev) {
                    prev->right = NULL;
                    o = prev;
                }
                if (p == NULL && o && o->val > root->val) p = o;
                if (p && root->val < p->val) q = root;
                o = root;
                root = root->right;
            }
        }
        if (p && q) {
            swap(p->val, q->val);
        }
    }
};