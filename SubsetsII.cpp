class Solution {
public:
    void dfs(int start, const vector<int> &nums, vector<int> &subset, vector<vector<int>> &result) {
        if (start >= nums.size()) {
            result.push_back(subset);
            return;
        }
        int end = start;
        while (end + 1 < nums.size() && nums[end + 1] == nums[start]) end++;
        dfs(end + 1, nums, subset, result);
        for (int i = start; i <= end; i++) {
            subset.push_back(nums[start]);
            dfs(end + 1, nums, subset, result);
        }
        subset.erase(subset.end() - (end - start + 1), subset.end());
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int> subset;
        dfs(0, nums, subset, result);
        return result;
    }
};