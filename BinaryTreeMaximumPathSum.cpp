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
    int dfs(TreeNode* root, int &ans) {
        if (root == NULL) return 0;
        int left = max(dfs(root->left, ans), 0);
        int right = max(dfs(root->right, ans), 0);
        ans = max(ans, root->val + left + right);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = root->val;
        dfs(root, ans);
        return ans;
    }
};