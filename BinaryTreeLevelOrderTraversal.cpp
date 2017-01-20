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
    void dfs(TreeNode *p, int depth, vector<vector<int>> &result) {
        if (p == NULL) return;
        if (depth >= result.size()) {
            result.push_back(vector<int>{p->val});
        } else {
            result[depth].push_back(p->val);
        }
        dfs(p->left, depth + 1, result);
        dfs(p->right, depth + 1, result);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
};