class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum > 0) sum += nums[i];
            else sum = nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};