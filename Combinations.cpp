class Solution {
public:
    void dfs(int start, int n, int k, vector<int> &com, vector<vector<int>> &result) {
        if (com.size() == k) {
            result.push_back(com);
            return;
        }
        for (int i = start; i <= n; i++) {
            com.push_back(i);
            dfs(i + 1, n, k, com, result);
            com.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if (n < k) return result;
        vector<int> com;
        dfs(1, n, k, com, result);
        return result;
    }
};