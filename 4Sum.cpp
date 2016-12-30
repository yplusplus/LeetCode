class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j - 1 > i && nums[j - 1] == nums[j]) continue;
                int L = j + 1, R = nums.size() - 1;
                while (L < R) {
                    int sum = nums[i] + nums[j] + nums[L] + nums[R] - target;
                    if (sum > 0) {
                        R--;
                    } else if (sum < 0) {
                        L++;
                    } else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[L], nums[R]});
                        while (L + 1 < R && nums[L + 1] == nums[L]) L++;
                        while (R - 1 > L && nums[R - 1] == nums[R]) R--;
                        L++, R--;
                    }
                }
            }
        }
        return result;
    }
};