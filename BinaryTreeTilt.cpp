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
    int findTilt(TreeNode* root) {
        int ans = 0;
        findTilt(root, ans);
        return ans;
    }
    int findTilt(TreeNode *root, int &ans) {
        if (root == NULL) return 0;
        int lsum = findTilt(root->left, ans);
        int rsum = findTilt(root->right, ans);
        ans += abs(lsum - rsum);
        return lsum + rsum + root->val;
    }
};