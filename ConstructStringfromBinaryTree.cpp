/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
    public:
        string tree2str(TreeNode* t) {
            string str;
            tree2str(t, str);
            return str;
            vector<char> vec;
            tree2str(t, vec);
            return string(vec.data(), vec.size());
        }
        void tree2str(TreeNode *t, vector<char> &vec) {
            if (t == NULL) return;
            string str = to_string(t->val);
            vec.insert(vec.end(), str.begin(), str.end());
            if (t->left != NULL || t->right != NULL) {
                vec.push_back('(');
                tree2str(t->left, vec);
                vec.push_back(')');
            }
            if (t->right != NULL) {
                vec.push_back('(');
                tree2str(t->right, vec);
                vec.push_back(')');
            }
        }
        void tree2str(TreeNode *t, string &str) {
            if (t == NULL) return;
            str += to_string(t->val);
            if (t->left == NULL && t->right == NULL) return;
            if (t->left != NULL || t->right != NULL) {
                str += '(';
                tree2str(t->left, str);
                str += ')';
            }
            if (t->right != NULL) {
                str += '(';
                tree2str(t->right, str);
                str += ')';
            }
        }
};
