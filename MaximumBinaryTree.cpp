/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            if (nums.empty()) return NULL;
            vector<TreeNode *> links;
            for (int i = 0; i < nums.size(); i++) {
                TreeNode *last_pop = NULL;
                while (!links.empty() && links.back()->val <= nums[i]) {
                    last_pop = links.back();
                    links.pop_back();
                }
                TreeNode *node = new TreeNode(nums[i]);
                node->left = last_pop;
                if (!links.empty()) links.back()->right = node;
                links.push_back(node);
            }
            return links[0];
        }
};
