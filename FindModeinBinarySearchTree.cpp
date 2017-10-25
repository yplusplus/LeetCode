/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
class Solution {
    public:
        void updateResult(int val, int val_freq) {
            if (val_freq == 0) return;
            if (val_freq < current_max_frequence) return;
            if (val_freq > current_max_frequence) result.clear();
            result.push_back(val);
            current_max_frequence = val_freq;
        }
        void dfs(TreeNode *root, int &last_val, int &last_val_freq) {
            if (root->left) dfs(root->left, last_val, last_val_freq);
            if (last_val != root->val) {
                updateResult(last_val, last_val_freq);
                last_val = root->val;
                last_val_freq = 1;
            } else {
                last_val_freq++;
            }
            if (root->right) dfs(root->right, last_val, last_val_freq);
        }
        vector<int> findMode(TreeNode* root) {
            current_max_frequence = 0;
            if (root == NULL) return result;
            int last_val = 0, last_val_freq = 0;
            dfs(root, last_val, last_val_freq);
            updateResult(last_val, last_val_freq);
            return result;
        }
    private:
        vector<int> result;
        int current_max_frequence;
};
