class Solution {
public:
    void dfs(vector<string> &result, int now, int n, int left, string &str) {
        if (2 * n == now) {
            result.push_back(str);
            return;
        }
        if (left + 1 <= 2 * n - now) {
            str[now] = '(';
            dfs(result, now + 1, n, left + 1, str);
        }
        if (left > 0) {
            str[now] = ')';
            dfs(result, now + 1, n, left - 1, str);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str(2 * n, '(');
        dfs(result, 0, n, 0, str);
        return result;
    }
};