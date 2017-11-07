// O(n*2^n)
class Solution {
public:
    int countArrangement(int N) {
        int all = 1 << N;
        vector<int> dp(all);
        dp[0] = 1;
        for (int mask = 0; mask < all; mask++) {
            if (dp[mask] == 0) continue;
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) cnt++;
            }
            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) continue;
                if ((i + 1) % (cnt + 1) == 0 || (cnt + 1) % (i + 1) == 0)
                    dp[mask | (1 << i)] += dp[mask];
            }
        }
        return dp[all - 1];
    }
};