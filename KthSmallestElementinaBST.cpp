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
        int kthSmallest(TreeNode* root, int k, int &ans) {
            int n = 0;
            if (root->left) n += kthSmallest(root->left, k, ans);
            if (n >= k) return n;
            if (++n == k) {
                ans = root->val;
                return k;
            }
            if (root->right) n += kthSmallest(root->right, k - n, ans);
            return n;
        }
        int kthSmallest(TreeNode* root, int k) {
            int ans = 0;
            kthSmallest(root, k, ans);
            return ans;
        }
};
