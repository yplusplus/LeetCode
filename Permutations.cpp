class Solution {
public:
    void dfs(vector<int> &nums, int now, vector<vector<int>> &result) {
        if (now >= nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = now; i < nums.size(); i++) {
            swap(nums[i], nums[now]);
            dfs(nums, now + 1, result);
            swap(nums[i], nums[now]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        dfs(nums, 0, result);
        return result;
    }
};