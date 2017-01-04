class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                int any = false;
                for (int i = 0; i <= n; i++) {
                    if (dp[i][j-1]) any = true;
                    dp[i][j] = any;
                }
            } else {
                for (int i = 1; i <= n; i++) {
                    dp[i][j] = dp[i-1][j-1] && (p[j-1] == '?' || p[j-1] == s[i-1]);
                }
            }
        }
        return dp[n][m];
    }
};