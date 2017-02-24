class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (i - 2 >= 0)
                dp[i] = max(dp[i], dp[i - 2]);
            if (i - 3 >= 0)
                dp[i] = max(dp[i], dp[i - 3]);
            dp[i] += nums[i];
        }
        return max(dp[n - 2], dp[n - 1]);
    }
};