class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if (n + m != s3.length()) return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else {
                    if (i > 0 && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j])
                        dp[i][j] = true;
                    if (j > 0 && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1])
                        dp[i][j] = true;
                }
            }
        }
        return dp[n][m];
    }
};