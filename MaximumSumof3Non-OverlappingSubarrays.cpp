class Solution {
    public:
        typedef pair<long long, vector<int> > State;
        vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            std::vector<vector<State>> dp(4, vector<State>(n + 1));
            vector<long long> sum(n + 1);
            for (int i = n - 1; i >= 0; i--) {
                sum[i] = sum[i + 1] + nums[i];
            }
            for (int i = 1; i <= 3; i++) {
                for (int j = n - 1; j >= 0; j--) {
                    dp[i][j] = dp[i][j + 1];
                    if (j + k <= n) {
                        long long val = dp[i - 1][j + k].first + sum[j] - sum[j + k];
                        if (val >= dp[i][j].first) {

                            vector<int> tmp = dp[i - 1][j + k].second;
                            tmp.insert(tmp.begin(), j);
                            dp[i][j] = State{val, tmp};
                        }
                    }
                }
            }

            return dp[3][0].second;
        }
};
