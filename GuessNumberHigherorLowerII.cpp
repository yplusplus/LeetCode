class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return getMoneyAmount(1, n, dp);
    }
    int getMoneyAmount(int L, int R, vector<vector<int>> &dp) {
        if (L >= R) return 0;
        if (dp[L][R] != -1) return dp[L][R];
        int res = INT_MAX;
        for (int i = L; i <= R; i++) {
            res = min(res, max(getMoneyAmount(L, i - 1, dp), getMoneyAmount(i + 1, R, dp)) + i);
        }
        return dp[L][R] = res;
    }
};