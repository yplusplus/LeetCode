class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n), pre(n);
        int z = 0;
        for (int i = 0; i < n; i++) {
            int x = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] > dp[x]) x = j;
                }
            }
            dp[i] = dp[x] + 1;
            pre[i] = x;
            if (dp[i] >= dp[z]) z = i;
        }
        
        vector<int> subset;
        subset.push_back(nums[z]);
        while (z != pre[z]) {
            z = pre[z];
            subset.push_back(nums[z]);
        }
        
        return subset;
    }
};