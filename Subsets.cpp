class Solution {
public:
    void dfs(const vector<int> &nums, int now, vector<int> &subset, vector<vector<int>> &result) {
        if (now == nums.size()) {
            result.push_back(subset);
            return;
        }
        // selected
        subset.push_back(nums[now]);
        dfs(nums, now + 1, subset, result);
        subset.pop_back();
        // non-seleted
        dfs(nums, now + 1, subset, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(nums, 0, subset, result);
        return result;
    }
};