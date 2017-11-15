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
    int findFrequentTreeSum(TreeNode *root, unordered_map<int, int> &hash_table) {
        if (root == NULL) return 0;
        int sum = root->val;
        sum += findFrequentTreeSum(root->left, hash_table);
        sum += findFrequentTreeSum(root->right, hash_table);
        hash_table[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        unordered_map<int, int> hash_table;
        findFrequentTreeSum(root, hash_table);
        int max_frequent = 0;
        for (auto it = hash_table.begin(); it != hash_table.end(); it++) {
            if (it->second > max_frequent) {
                result.clear();
                max_frequent = it->second;
            }
            if (max_frequent == it->second) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};