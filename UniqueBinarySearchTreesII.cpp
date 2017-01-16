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
    void dfs(int L, int R, vector<TreeNode *> &roots) {
        if (L > R) {
            roots.push_back(NULL);
            return;
        }
        if (L == R) {
            roots.push_back(new TreeNode(L));
            return;
        }
        vector<TreeNode *> left, right;
        for (int i = L; i <= R; i++) {
            left.clear();
            right.clear();
            dfs(L, i - 1, left);
            dfs(i + 1, R, right);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    roots.push_back(node);
                }
            }
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> roots;
        if (n > 0) dfs(1, n, roots);
        return roots;
    }
};