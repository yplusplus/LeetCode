class Solution {
public:
    void dfs(vector<int> &candidates, int now, int target, vector<int> &used, vector<vector<int>> &result, bool chosen) {
        if (target == 0) {
            result.push_back(used);
            return;
        }
        if (now >= candidates.size()) return;
        if (candidates[now] > target) return;
        dfs(candidates, now + 1, target, used, result, false);
        if (now == 0 || candidates[now] != candidates[now - 1] || chosen) {
            used.push_back(candidates[now]);
            dfs(candidates, now + 1, target - candidates[now], used, result, true);
            used.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) return result;
        sort(candidates.begin(), candidates.end());
        vector<int> used;
        dfs(candidates, 0, target, used, result, true);
        return result;
    }
};