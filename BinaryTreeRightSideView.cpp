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
    void rightSideView(TreeNode *root, int level, vector<int> &view) {
        if (root == NULL) return;
        if ((int)view.size() <= level) view.push_back(root->val);
        rightSideView(root->right, level + 1, view);
        rightSideView(root->left, level + 1, view);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        rightSideView(root, 0, view);
        return view;
    }
};