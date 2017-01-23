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
    void dfs(TreeNode *root, int depth, vector<vector<int>> &result) {
        if (root == NULL) return;
        if (depth >= result.size()) result.resize(depth + 1);
        result[depth].push_back(root->val);
        dfs(root->left, depth + 1, result);
        dfs(root->right, depth + 1, result);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        dfs(root, 0, result);
        reverse(result.begin(), result.end());
        return result;
    }
};