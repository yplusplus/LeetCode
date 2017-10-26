class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int max_num = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (nums[i] > max_num) max_num = nums[i];
        }
        
        if ((sum % k > 0) || (max_num > sum / k))
            return false;
        
        int subset_sum = sum / k;
        int n = nums.size();
        int all = 1 << n;
        vector<bool> dp(all);
        dp[0] = true;
        vector<int> sum2(all);
        for (int state = 0; state < all; state++) {
            if (!dp[state]) continue;
            for (int i = 0; i < n; i++) {
                if (state & (1 << i)) 
                    continue;
                int nxt_state = state | (1 << i);
                if (!dp[nxt_state] && nums[i] <= subset_sum - sum2[state] % subset_sum) {
                    dp[nxt_state] = true;
                    sum2[nxt_state] = sum2[state] + nums[i];
                }
            }
        }
        
        return dp[all - 1];
    }
};