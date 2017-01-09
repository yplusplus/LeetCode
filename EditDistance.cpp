class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if (m == 0 || n == 0) return max(m, n);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, max(m, n)));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // equal
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                // delete
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                // replace
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                // insert
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        return dp[m][n];
    }
};