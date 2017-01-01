class Solution {
public:
    void dfs(vector<int> &candidates, int now, int target, vector<int> &used, vector<vector<int>> &result) {
        if (now == candidates.size()) {
            if (target == 0) {
                result.push_back(used);
            }
            return;
        }
        dfs(candidates, now + 1, target, used, result);
        int upper = target / candidates[now];
        for (int i = 1; i <= upper; i++) {
            used.push_back(candidates[now]);
            dfs(candidates, now + 1, target - i * candidates[now], used, result);
        }
        for (int i = 1; i <= upper; i++) used.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> used;
        dfs(candidates, 0, target, used, result);
        return result;
    }
    
};