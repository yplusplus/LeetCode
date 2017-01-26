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
    void sumNumbers(TreeNode *root, int &sum, string path) {
        if (root == NULL) return;
        string cur = path + (char)(root->val + '0');
        if (root->left == NULL && root->right == NULL) {
            sum += stoi(cur);
            return;
        }
        if (root->left) sumNumbers(root->left, sum, cur);
        if (root->right) sumNumbers(root->right, sum, cur);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        sumNumbers(root, ans, "");
        return ans;
    }
};