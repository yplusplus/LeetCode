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
    TreeNode* sortedArrayToBST(const vector<int> &nums, int L, int R) {
        if (L > R) return NULL;
        int M = (L + R) / 2;
        TreeNode *p = new TreeNode(nums[M]);
        p->left = sortedArrayToBST(nums, L, M - 1);
        p->right = sortedArrayToBST(nums, M + 1, R);
        return p;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, (int)nums.size() - 1);
    }
};