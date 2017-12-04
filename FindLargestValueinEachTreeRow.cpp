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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        getLargestValues(root, 0, result);
        return result;
    }
    void getLargestValues(TreeNode *root, int level, vector<int> &result) {
        if (root == NULL) return;
        if (result.size() <= level) {
            result.push_back(root->val);
        } else if (root->val > result[level]) {
            result[level] = root->val;
        }
        getLargestValues(root->left, level + 1, result);
        getLargestValues(root->right, level + 1, result);
    }
};