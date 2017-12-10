class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            if (amount == 0) return 0;
            vector<int> dp(amount + 1, -1);
            dp[0] = 0;
            for (int coin : coins) {
                for (int w = 0; w + coin <= amount; w++) {
                    if (dp[w] < 0) continue;
                    if (dp[w + coin] == -1 || dp[w + coin] > dp[w] + 1) {
                        dp[w + coin] = dp[w] + 1;
                    }
                }
            }
            return dp[amount];
        }
};
