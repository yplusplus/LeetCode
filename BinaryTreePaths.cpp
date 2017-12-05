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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root != NULL)
            binaryTreePaths(root, res, "");
        return res;
    }
    void binaryTreePaths(TreeNode *root, vector<string> &res, string str) {
        if (str.length() > 0) str += "->";
        str += to_string(root->val);
        // leaf
        if (root->left == NULL && root->right == NULL) {
            res.push_back(str);
            return;
        }
        if (root->left != NULL) binaryTreePaths(root->left, res, str);
        if (root->right != NULL) binaryTreePaths(root->right, res, str);
    }
};