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
        bool isBalanced(TreeNode *root, int &high) {
            if (root == NULL) {
                high = 0;
                return true;
            }
            int lhigh = 0, rhigh = 0;
            if (isBalanced(root->left, lhigh) 
                    && isBalanced(root->right, rhigh) 
                    && abs(lhigh - rhigh) <= 1) {
                high = max(lhigh, rhigh) + 1;
                return true;
            }
            return false;
        }
        bool isBalanced(TreeNode* root) {
            int high = 0;
            return isBalanced(root, high);
        }
};
